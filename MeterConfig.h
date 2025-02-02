#ifndef MeterConfig_h
#define MeterConfig_h

#include "Arduino.h"


//Meter models you want to enable to be read
// 0 = Disable
// 1 = Enable

#define ___PM2120 0
#define ___Ci3_01 0
#define ___EM_3490_SS 0
#define ___MFM_376 0
#define ___LG5310 0
#define ___POLARSTAR 1
//-----------------------------------------------

//-----------------------------------------------
//Serial Monitor Enable or Disable Selection
// 0 = Disable
// 1 = Enable

#define SerialMonitor 1
//-----------------------------------------------


//String SupportedMeters[] = {"Ci3_01","PM2120","EM_3490_SS","LG5310"};

extern int _PM2120      = 0;    //Schnieder 
extern int _EM_3490_SS  = 1;    //Ziegler
extern int _Ci3_01      = 2;    //Crompton
extern int _MFM_376     = 3;    //Selec
extern int _LG5310      = 4;    //ELmeasure
extern int _POLARSTAR   = 5;    //Polarstar (Elcontrol) 

#endif
