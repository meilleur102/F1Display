/*
  TFT_CS 15
  TFT_RST 4
  TFT_DC 2
  TFT_MOSI 23
  TFT_SCLK 18
  TFT_MISO 19
*/

#include <Arduino.h>
#include <User_Setup_Select.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <FlickerFreePrint.h>
#include <WelcomeAnim.h>
#include <iRacing.h>

TFT_eSPI tft;

TFT_eSprite pitSprite = TFT_eSprite(&tft);

TFT_eSprite gear1 = TFT_eSprite(&tft);
TFT_eSprite gear2 = TFT_eSprite(&tft);
TFT_eSprite gear3 = TFT_eSprite(&tft);
TFT_eSprite gear4 = TFT_eSprite(&tft);
TFT_eSprite gear5 = TFT_eSprite(&tft);
TFT_eSprite gear6 = TFT_eSprite(&tft);
TFT_eSprite gear7 = TFT_eSprite(&tft);
TFT_eSprite gear8 = TFT_eSprite(&tft);

TFT_eSprite drs = TFT_eSprite(&tft);

char terminator = '\n';
String data;

void CreateDefaultSprite();
void GetPitLimiter(char isOn[1]);
void GetDRS(String state);
void GetGearSync();

TaskHandle_t Task1;
TaskHandle_t Task2;

void task1Func(void *parameter);
void task2Func(void *parameter);

void setup()
{
  Serial.begin(230400);
  Serial1.begin(230400);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  //GetWelcomeAnim();
  CreateDefaultSprite();
  GetRaceDefault();

  delay(500);
}


void loop()
{
  while (Serial.available())
  {
    data = Serial.readStringUntil(terminator);
    String s = data.substring(0, 2);
    data = data.substring(2);
    int strLen = data.length() + 1;
    char chararr[strLen];
    data.toCharArray(chararr, strLen);
    int value = s.toInt();

    switch (value)
    {
    case 00:
      GetDelta(chararr);
      break;

    case 01:
      UpdateLap(chararr);
      break;

    case 02:
      GetCurrentGear(chararr);
      break;

    case 03:
      GetBrakeBias(chararr);
      break;

    case 04:
      GetLast(chararr);
      break;

    case 05:
      GetBattery(chararr);
      break;

    case 99:
      GetPitLimiter(chararr);
      break;

    default:
      break;
    }
  }
}

#pragma region SPRITE

void GetDRS(String state)
{
  int x = 116;
  int y = 0;

  if (state == "OFF")
  {
    drs.fillSprite(TFT_TRANSPARENT);
    drs.pushSprite(x, y);
    GetGearSync();
  }
  else
  {
    drs.fillSprite(TFT_GREEN);
    drs.pushSprite(x, y);

    tft.setFreeFont(C18B);
    tft.setTextColor(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(state, drs.width() / 2 + x, drs.height() / 2 + y);
  }
}

void GetGearSync()
{

  gear1.fillSprite(TFT_WHITE);
  gear1.pushSprite(120, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("1", gear1.width() / 2 + 120, gear1.height() / 2 + 3);

  gear2.fillSprite(TFT_WHITE);
  gear2.pushSprite(151, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("2", gear2.width() / 2 + 151, gear2.height() / 2 + 3);

  gear3.fillSprite(TFT_WHITE);
  gear3.pushSprite(182, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("3", gear3.width() / 2 + 182, gear3.height() / 2 + 3);

  gear4.fillSprite(TFT_WHITE);
  gear4.pushSprite(213, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("4", gear4.width() / 2 + 213, gear4.height() / 2 + 3);

  gear5.fillSprite(TFT_WHITE);
  gear5.pushSprite(244, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("5", gear5.width() / 2 + 244, gear5.height() / 2 + 3);

  gear6.fillSprite(TFT_WHITE);
  gear6.pushSprite(275, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("6", gear6.width() / 2 + 275, gear6.height() / 2 + 3);

  gear7.fillSprite(TFT_WHITE);
  gear7.pushSprite(306, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("7", gear7.width() / 2 + 306, gear7.height() / 2 + 3);

  gear8.fillSprite(TFT_WHITE);
  gear8.pushSprite(337, 6);
  tft.setFreeFont(C18B);
  tft.setTextColor(TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("8", gear8.width() / 2 + 337, gear8.height() / 2 + 3);
}

void GetPitLimiter(char isOn[1])
{
  int x = 5;
  int y = 113;
  int w = 151;
  int h = 209;
  if (isOn[0] == '1')
  {
    pitSprite.setFreeFont(C24B);
    int tw = tft.textWidth("PIT LIM");

    pitSprite.fillSprite(TFT_YELLOW);
    pitSprite.setTextColor(TFT_BLACK);
    pitSprite.setTextDatum(MC_DATUM);
    pitSprite.drawString("PIT LIM", w / 2, 20);
    pitSprite.pushSprite(x, y);
  }

  if (isOn[0] == '2')
  {
    pitSprite.fillSprite(TFT_BLACK);
    pitSprite.pushSprite(x, y);
  }
}

void CreateDefaultSprite()
{
  pitSprite.createSprite(164, 209);
  // gear1.setColorDepth(1);
  gear1.createSprite(27, 27);
  // gear2.setColorDepth(1);
  gear2.createSprite(27, 27);
  // gear3.setColorDepth(1);
  gear3.createSprite(27, 27);
  // gear3.setColorDepth(1);
  gear4.createSprite(27, 27);
  // gear5.setColorDepth(1);
  gear5.createSprite(27, 27);
  // gear6.setColorDepth(1);
  gear6.createSprite(27, 27);
  // gear7.setColorDepth(1);
  gear7.createSprite(27, 27);
  // gear8.setColorDepth(1);
  gear8.createSprite(27, 27);

  drs.createSprite(252, 35);
}

#pragma endregion
