#ifndef Parameters_var_h
#define Parameters_var_h

#include "Arduino.h";

String parameter_names[]=
{
  "vR",    //  0 = VR_phase
  "vY",   //  1 = VY_phase
  "vB",   //  2 = VB_phase
  "cR",   //  3 = IR_phase
  "cY",   //  4 = IY_phase
  "cB",   //  5 = IB_phase
  "rlR",  //  6 = Watts_R_phase
  "rlY",  //  7 = Watts_Y_phase
  "rlB",  //  8 = Watts_B_phase
  "atR",  //  9 = VA_R
  "atY",  // 10 = VA_Y
  "atB",  // 11 = VA_B
  "reR",  // 12 = VAR_R
  "reY",  // 13 = VAR_Y
  "reB",  // 14 = VAR_B
  "pfR",  // 15 = pfR
  "pfY",  // 16 = pfY
  "pfB",  // 17 = pfB
  //"vLN",  // 18 = Average line to neutral voltage
  //"vLL",  // 19 = Average line to line voltage
  "cT",   // 20 = Total current
  "rlT",  // 21 = Total Watt power
  "atT",  // 22 = Total VA
  "reT",  // 23 = Total VAR
  "f",    // 24 = Frequency
  "mpT",  // 25 = Max watt demand
  "maT",  // 26 = Max VA demand
  "vRY",  // 27 = vRY
  "vYB",  // 28 = vYB
  "vRB",  // 29 = vRB
  "cN",   // 30 = Neutral current
  "tvR",  // 31 = THD Voltage_R
  "tvY",  // 32 = THD Voltage_Y
  "tvB",  // 33 = THD Voltage_B
  "tcR",  // 34 = THD Current_R
  "tcY",  // 35 = THD Current_Y
  "tcB",  // 36 = THD Current_B
  "tvLN", // 37 = THD Average line to neutral volts
  "tcLN", // 38 = THD Avg line current
  "mcR",  // 39 = Maximum Current demand R_phase
  "mcY",  // 40 = Maximum Current demand Y_phase
  "mcB",  // 41 = Maximum Current demand B_phase
  "tvRY", // 42 = THD vRY
  "tvYB", // 43 = THD vYB
  "tvRB", // 44 = THD vRB
  "tvLL", // 45 = THD Average line to line volts
  "pfA",  // 46 = Average power factor pfA
  "en",   // 47 = Watt_hr
  "eT",    // 48 = Load hours
  

  "cHA1",    //49 =Current A Harmonics
  "cHA2",    //49 =Current A Harmonics
  "cHA3",    //49 =Current A Harmonics
  "cHA4",    //49 =Current A Harmonics
  "cHA5",    //49 =Current A Harmonics
  "cHA6",    //49 =Current A Harmonics
  "cHA7",    //49 =Current A Harmonics
  "cHA8",    //49 =Current A Harmonics
  "cHA9",    //49 =Current A Harmonics
  "cHA10",   //49 =Current A Harmonics
  "cHA11",   //49 =Current A Harmonics
  "cHA12",   //49 =Current A Harmonics
  "cHA13",   //49 =Current A Harmonics
  "cHA14",   //49 =Current A Harmonics
  "cHA15",   //49 =Current A Harmonics
  "cHA16",    //49 =Current A Harmonics
  "cHA17",    //49 =Current A Harmonics
  "cHA18",    //49 =Current A Harmonics
  "cHA19",    //49 =Current A Harmonics
  "cHA20",    //49 =Current A Harmonics
  "cHA21",    //49 =Current A Harmonics
  "cHA22",    //49 =Current A Harmonics
  "cHA23",    //49 =Current A Harmonics
  "cHA24",    //49 =Current A Harmonics
  "cHA25",    //49 =Current A Harmonics
  "cHA26",    //49 =Current A Harmonics
  "cHA27",    //49 =Current A Harmonics
  "cHA28",    //49 =Current A Harmonics
  "cHA29",    //49 =Current A Harmonics
  "cHA30",    //49 =Current A Harmonics
  "cHA31",    //49 =Current A Harmonics

  "cHB1",    //49 =Current B Harmonics
  "cHB2",    //49 =Current B Harmonics
  "cHB3",    //49 =Current B Harmonics
  "cHB4",   //49 =Current B Harmonics
  "cHB5",    //49 =Current B Harmonics
  "cHB6",    //49 =Current B Harmonics
  "cHB7",    //49 =Current B Harmonics
  "cHB8",   //49 =Current B Harmonics
  "cHB9",    //49 =Current B Harmonics
  "cHB10",    //49 =Current B Harmonics
  "cHB11",    //49 =Current B Harmonics
  "cHB12",    //49 =Current B Harmonics
  "cHB13",    //49 =Current B Harmonics
  "cHB14",    //49 =Current B Harmonics
  "cHB15",    //49 =Current B Harmonics
  "cHB16",    //49 =Current B Harmonics
  "cHB17",    //49 =Current B Harmonics
  "cHB18",    //49 =Current B Harmonics
  "cHB19",    //49 =Current B Harmonics
  "cHB20",    //49 =Current B Harmonics
  "cHB21",    //49 =Current B Harmonics
  "cHB22",    //49 =Current B Harmonics
  "cHB23",    //49 =Current B Harmonics
  "cHB24",    //49 =Current B Harmonics
  "cHB25",    //49 =Current B Harmonics
  "cHB26",    //49 =Current B Harmonics
  "cHB27",    //49 =Current B Harmonics
  "cHB28",    //49 =Current B Harmonics
  "cHB29",    //49 =Current B Harmonics
  "cHB30",    //49 =Current B Harmonics
  "cHB31",    //49 =Current B Harmonics
  //Current Harmonic C
  "cHC1",    //49 =Current C Harmonics
  "cHC2",    //49 =Current C Harmonics
  "cHC3",    //49 =Current C Harmonics
  "cHC4",   //49 =Current C Harmonics
  "cHC5",    //49 =Current C Harmonics
  "cHC6",    //49 =Current C Harmonics
  "cHC7",    //49 =Current C Harmonics
  "cHC8",   //49 =Current C Harmonics
  "cHC9",    //49 =Current C Harmonics
  "cHC10",    //49 =Current C Harmonics
  "cHC11",    //49 =Current C Harmonics
  "cHC12",    //49 =Current C Harmonics
  "cHC13",    //49 =Current C Harmonics
  "cHC14",    //49 =Current C Harmonics
  "cHC15",    //49 =Current C Harmonics
  "cHC16",    //49 =Current C Harmonics
  "cHC17",    //49 =Current C Harmonics
  "cHC18",    //49 =Current C Harmonics
  "cHC19",    //49 =Current C Harmonics
  "cHC20",    //49 =Current C Harmonics
  "cHC21",    //49 =Current C Harmonics
  "cHC22",    //49 =Current C Harmonics
  "cHC23",    //49 =Current C Harmonics
  "cHC24",    //49 =Current C Harmonics
  "cHC25",    //49 =Current C Harmonics
  "cHC26",    //49 =Current C Harmonics
  "cHC27",    //49 =Current C Harmonics
  "cHC28",    //49 =Current C Harmonics
  "cHC29",    //49 =Current C Harmonics
  "cHC30",    //49 =Current C Harmonics
  "cHC31",    //49 =Current C Harmonics


  /*"vHA1",
"vHA2",
"vHA3",
"vHA4",
"vHA5",
"vHA6",
"vHA7",
"vHA8",
"vHA9",
"vHA10",
"vHA11",
"vHA12",
"vHA13",
"vHA14",
"vHA15",
"vHA16",
"vHA17",
"vHA18",
"vHA19",
"vHA20",
"vHA21",
"vHA22",
"vHA23",
"vHA24",
"vHA25",
"vHA26",
"vHA27",
"vHA28",
"vHA29",
"vHA30",
"vHA31",




"vHB1",
"vHB2",
"vHB3",
"vHB4",
"vHB5",
"vHB6",
"vHB7",
"vHB8",
"vHB9",
"vHB10",
"vHB11",
"vHB12",
"vHB13",
"vHB14",
"vHB15",
"vHB16",
"vHB17",
"vHB18",
"vHB19",
"vHB20",
"vHB21",
"vHB22",
"vHB23",
"vHB24",
"vHB25",
"vHB26",
"vHB27",
"vHB28",
"vHB29",
"vHB30",
"vHB31",



 "vHC1",
"vHC2",
"vHC3",
"vHC4",
"vHC5",
"vHC6",
"vHC7",
"vHC8",
"vHC9",
"vHC10",
"vHC11",
"vHC12",
"vHC13",
"vHC14",
"vHC15",
"vHC16",
"vHC17",
"vHC18",
"vHC19",
"vHC20",
"vHC21",
"vHC22",
"vHC23",
"vHC24",
"vHC25",
"vHC26",
"vHC27",
"vHC28",
"vHC29",
"vHC30",
"vHC31",*/
"DIPS",
"SWELLS"
  
  };

#endif
