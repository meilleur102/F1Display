#ifndef IRACING_h
#define IRACING_h
#include <TFT_eSPI.h>
#include <FreeFont.h>
#include <Fonts/Custom/calibrib18pt7b.h>
#include <Fonts/Custom/calibrib24pt7b.h>
#include <Fonts/Custom/calibri12pt7b.h>
#include <Fonts/Custom/calibrib12pt7b.h>
#include <Fonts/Custom/calibri7pt7b.h>
#include <Fonts/Custom/calibrib16pt7b.h>
#include <Fonts/Custom/calibri80pt7b.h>
#include <Fonts/Custom/calibrib20pt7b.h>
#include <Fonts/Custom/calibrib15pt7b.h>
#include <Fonts/Custom/calibrib28pt7b.h>
#include <Fonts/Custom/calibrib11pt7b.h>


#include <FlickerFreePrint.h>

void GetRaceDefault();


void GetCurrentGear(char gear[1]);
void GetDeploy();
void GetDeployMode();
void GetDelta(char delta[6]);
void GetEngineMode();
void GetBrakeBias(char gear[1]);
void GetBattery(char batt[3]);
void GetEngineBrake();
void GetLap();
void GetLitter();
void GetFuel();
void GetLast(char last[8]);
void GetBest(char best[8]);
void GetDiff();

void UpdateLap(char lap[2]);
// void GetGearSync(TFT_eSprite gear1,TFT_eSprite gear2,TFT_eSprite gear3,TFT_eSprite gear4,
//                 TFT_eSprite gear5,TFT_eSprite gear6,TFT_eSprite gear7,TFT_eSprite gear8, TFT_eSprite drs, String state);
#endif







//char terminator = '\n';
//String data = "";
// void iRacing(){

//   if(data == ""){
//     data = "Welcome";
//   }
//     tft.setTextDatum(MC_DATUM);
//     tft.drawString(data, tft.width() / 2, tft.height() / 2);
//     //tft.print(data);


//   while(Serial.available()){
//     data = "";
//     data = Serial.readStringUntil(terminator);
//     data.remove('\r');
//     tft.print(data);
//   }
// }

