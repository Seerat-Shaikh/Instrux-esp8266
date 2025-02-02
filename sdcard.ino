#include <ModbusMaster.h>
#include <math.h>
#include <SoftwareSerial.h>
#include "POLARSTAR.h";
#include <SPI.h>
#include <SD.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
//#include <TimeLib.h>
#include <Wire.h>
#include <RTClib.h>

const int chipSelect = 15;
const char* ssid = "NuNami";
const char* password = "Nunamipak";
File dataFile;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 5 * 3600, 60000);
RTC_DS3231 rtc;

ModbusMaster node;
String dataString = "";
int NumberOfParameters = sizeof(POLARSTAR) / sizeof(int);
float Acquired_Data[1][140];
float ParameterFailureValue = 77.7;
int MeterNo = 0;
uint8_t result;
int16_t datas[2];
SoftwareSerial RS485Serial(2, 0);

// Function to convert binary to Decimal
int binaryToDecimal(int n) {
    int dec_value = 0;
    int base = 1;
    int temp = n;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}

// Function to convert BCD to Decimal
uint32_t BCDToDecimal(uint32_t nDecimalValue) {
    uint32_t nResult = 0;
    int ncnt;
    int anHexValueStored[8];
    uint16_t unflag = 0;

    // Extract each hexadecimal value from the BCD value
    for (ncnt = 7; ncnt >= 0; ncnt--) {
        anHexValueStored[ncnt] = nDecimalValue & (0x0000000F << 4 * (7 - ncnt));  // Mask each 4-bit segment
        anHexValueStored[ncnt] = anHexValueStored[ncnt] >> 4 * (7 - ncnt);  // Shift it to the right

        // Check for invalid BCD values (values greater than 9)
        if (anHexValueStored[ncnt] > 9)
            unflag = 1;
    }

    // If invalid BCD value is detected, return 0
    if (unflag == 1) {
        return 0;
    } else {
        // Convert BCD digits to decimal
        for (ncnt = 0; ncnt < 8; ncnt++) {
            nResult = nResult + anHexValueStored[ncnt] * round(pow(10, (7 - ncnt)));  // Scale each digit
        }
        return nResult;
    }
}


void setup() {
    Serial.begin(115200);
    RS485Serial.begin(9600, SWSERIAL_8N1, 2, 0);
    node.begin(1, RS485Serial);
    Serial.println("Starting Polarstar communication...");

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");

    timeClient.begin();

    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        while (1);
    }
    if (rtc.lostPower()) {
        Serial.println("RTC lost power, setting initial time...");
        rtc.adjust(DateTime(2025, 1, 31, 10, 26, 30));
    }

    if (!SD.begin(chipSelect)) {
        Serial.println("SD card initialization failed!");
        while (true);
    }
    Serial.println("SD card initialized.");
}

void loop() {
    DateTime now = rtc.now();
    dataString = " " + String(now.year()) + "-" + String(now.month()) + "-" + String(now.day()) + "," + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()) + "," + dataString;

    const char* daysOfTheWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    Serial.print("RTC Time: ");

    //Serial.print(daysOfWeek[now.dayOfWeek()]); 
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]); Serial.print(" ");
    Serial.print(now.year()); Serial.print("-");
    Serial.print(now.month()); Serial.print("-");
    Serial.print(now.day()); Serial.print(" ");
    Serial.print(now.hour()); Serial.print(":");
    Serial.print(now.minute()); Serial.print(":");
    Serial.println(now.second());

    static unsigned long lastSyncTime = 0;
    unsigned long currentMillis = millis();
    if (WiFi.status() == WL_CONNECTED && currentMillis - lastSyncTime >= 60000) {
        timeClient.update();
        rtc.adjust(DateTime(timeClient.getEpochTime()));
        lastSyncTime = currentMillis;
        Serial.println("RTC synced with NTP");
    }
    

    for (int param = 0; param < NumberOfParameters; param++) {
        if (POLARSTAR[param] == 0xFFFF) {
            Acquired_Data[MeterNo][param] = ParameterFailureValue;
        } else {
            result = node.readInputRegisters(POLARSTAR[param], 2);
            if (result == node.ku8MBSuccess) {
                for (uint8_t j = 0; j < 2; j++) {
                    datas[j] = node.getResponseBuffer(j);
                }
                Acquired_Data[MeterNo][param] = BCDToDecimal(datas[0]) * pow(10, binaryToDecimal(datas[1]));
            }
            if (isnan(Acquired_Data[MeterNo][param])) {
                Acquired_Data[MeterNo][param] = ParameterFailureValue;
            }
        }
        if (result == node.ku8MBResponseTimedOut) {
            Serial.println("Response Timeout...");
            break;
        } else {
            Serial.print(" ");
            Serial.print(Acquired_Data[MeterNo][param]);
            dataString += String(Acquired_Data[MeterNo][param]);
            if (param < NumberOfParameters - 1) {
                dataString += ",";
            }
        }
        delay(10);
    }
    Serial.println();

    String fileName = String(now.day()) + "-" + String(now.month()) + "-" + String(now.year()) + ".csv";
    bool newFile = !SD.exists(fileName);
    dataFile = SD.open(fileName, FILE_WRITE);
    if (dataFile) {
      if (newFile) { 
        dataFile.println("Date,Time,VR_phase,VY_phase,VB_phase,IR_phase,IY_phase,IB_phase,Watts_R_phase,Watts_Y_phase,Watts_B_phase,VA_R,VA_Y,VA_B,VAR_R,VAR_Y,VAR_B,pfR,pfY,pfB,TC,TWP,TVA,TVAR,f,MWD,MVAD,vRY,vYB,vRB,NC,THD_vR,THD_vY,THD_vB,THD_cR,THD_cY,THD_cB,THD_aLN,tcLN,mcR,mcY,mcB,pfA,cHA1,cHA2,cHA3,cHA4,cHA5,cHA6,cHA7,cHA8,cHA9,cHA10,cHA11,cHA12,cHA13,cHA14,cHA15,cHB1,cHB2,cHB3,cHB4,cHB5,cHB6,cHB7,cHB8,cHB9,cHB10,cHB11,cHB12,cHB13,cHB14,cHB15,cHC1,cHC2,cHC3,cHC4,cHC5,cHC6,cHC7,cHC8,cHC9,cHC10,cHC11,cHC12,cHC13,cHC14,cHC15,DIPS,Swells");
       }
        //dataFile.println("Date,Time,VR_phase,VY_phase,VB_phase,IR_phase,IY_phase,IB_phase,Watts_R_phase,Watts_Y_phase,Watts_B_phase"); //VA_R	VA_Y	VA_B	VAR_R	VAR_Y	VAR_B	pfR	pfY	pfB	TC	TWP	TVA	TVAR	f	MWD	MVAD	vRY	vYB	vRB	NC	THD_vR	THD_vY	THD_vB	THD_cR	THD_cY	THD_cB	THD_aLN	tcLN	mcR	mcY	mcB	pfA	cHA1	cHA2	cHA3	cHA4	cHA5	cHA6	cHA7	cHA8	cHA9	cHA10	cHA11	cHA12	cHA13	cHA14	cHA15	cHB1	cHB2	cHB3	cHB4	cHB5	cHB6	cHB7	cHB8	cHB9	cHB10	cHB11	cHB12	cHB13	cHB14	cHB15	cHC1	cHC2	cHC3	cHC4	cHC5	cHC6	cHC7	cHC8	cHC9	cHC10	cHC11	cHC12	cHC13	cHC14	cHC15	DIPS	Swells"); // Modify as needed
        dataFile.println(dataString);
        dataFile.close();
        Serial.println("datastring saved to SD Card");
        //Serial.println(dataString);
        dataString = "";
    } else {
        Serial.println("Error opening file!");
     }
}
