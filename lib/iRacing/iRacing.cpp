// int hm = 1.1765;
#include <iRacing.h>
extern TFT_eSPI tft;

FlickerFreePrint<TFT_eSPI> Gear(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> Deploy(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> DeployNumber(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> DeployMode(&tft, TFT_WHITE);

FlickerFreePrint<TFT_eSPI> Delta(&tft, TFT_GREEN);
FlickerFreePrint<TFT_eSPI> Delta2(&tft, TFT_GREEN);


FlickerFreePrint<TFT_eSPI> EngineMode(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> BrakeBias(&tft, TFT_ORANGE);
FlickerFreePrint<TFT_eSPI> Batt(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> BattPercent(&tft, TFT_YELLOW);
FlickerFreePrint<TFT_eSPI> Eb(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> EbValue(&tft, TFT_ORANGE);
FlickerFreePrint<TFT_eSPI> LapCurrent(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> LapDash(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> LapTotal(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> Lap(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> LlLiters(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> LlLitersValue(&tft, TFT_GREEN);
FlickerFreePrint<TFT_eSPI> Fuel(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> FuelValue(&tft, TFT_GREEN);
FlickerFreePrint<TFT_eSPI> Last(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> LastValue(&tft, TFT_SKYBLUE);
FlickerFreePrint<TFT_eSPI> Best(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> BestValue(&tft, TFT_SKYBLUE);
FlickerFreePrint<TFT_eSPI> Diff(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> DiffE(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> DiffEValue(&tft, TFT_GREEN);
FlickerFreePrint<TFT_eSPI> DiffM(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> DiffMValue(&tft, TFT_ORANGE);
FlickerFreePrint<TFT_eSPI> DiffH(&tft, TFT_WHITE);
FlickerFreePrint<TFT_eSPI> DiffHValue(&tft, TFT_SKYBLUE);


void UpdateLap(char lap[2])
{
    tft.setFreeFont(C12B);
    tft.setCursor(370,25);
    LapCurrent.print(lap);
}

void GetRaceDefault()
{
    GetCurrentGear("N");
    GetDeployMode();
    GetEngineMode();
    GetBattery("100");
    GetEngineBrake();
    GetBrakeBias("00.0");
    GetDelta("+00.00");
    GetDeploy();
    GetLap();
    GetLitter();
    GetFuel();
    GetLast("0:01.00");
    GetBest("1:04.433");
    GetDiff();
}

void GetDiff()
{
    tft.setFreeFont(C7);
    tft.setCursor(10, 200);
    Diff.print("DIFF:-");
    tft.setFreeFont(C11);
    tft.setCursor(20,222);
    DiffE.print("E");
    tft.setCursor(35,220);
    DiffEValue.print("10");
    tft.setCursor(65,222);
    DiffM.print("M");
    tft.setCursor(90,220);
    DiffMValue.print("10");
    tft.setCursor(120,222);
    DiffH.print("H");
    tft.setCursor(140,220);
    DiffHValue.print("10");
}

void GetBest(char best[8])
{
    tft.setFreeFont(C7);
    tft.setCursor(15,250);
    Best.print("BEST:-");
    tft.setFreeFont(C20B);
    tft.setCursor(20, 285);
    BestValue.print("1:04.433");
}

void GetLast(char last[8])
{
    tft.setFreeFont(C7);
    tft.setCursor(290,250);
    Last.print("LAST:-");
    tft.setFreeFont(C24B);
    tft.setCursor(290,288);
    LastValue.print(last);
}

void GetFuel()
{
    tft.setFreeFont(C7);
    tft.setCursor(295,180);
    Fuel.print("FUEL (liters):-");
    tft.setFreeFont(C28B);
    tft.setCursor(305,220);
    FuelValue.print("110.00");
}

void GetLitter()
{
    tft.setFreeFont(C7);
    tft.setCursor(295,115);
    LlLiters.print("LL (liters):-");
    tft.setFreeFont(C28B);
    tft.setCursor(362,155);
    LlLitersValue.print("1.84");
}

void GetBrakeBias(char bias[3])
{
    tft.setFreeFont(C28B);
    tft.setCursor(325,85);
    BrakeBias.print(bias);
}

void GetLap()
{
    tft.setFreeFont(C12B);
    tft.setCursor(370,25);
    LapCurrent.print("01");
    tft.setFreeFont(C12);
    tft.setCursor(395, 30);
    LapDash.print("/");
    tft.setCursor(410,30);
    LapTotal.print("01");
    tft.setFreeFont(C12B);
    tft.setCursor(440,30);
    Lap.print("LAP");

}

void GetCurrentGear(char gear[])
{
    tft.setFreeFont(C80);
    tft.setCursor(190, 150);
    Gear.print(gear);
}

void GetDeployMode()
{
    tft.setFreeFont(C15B);
    tft.setCursor(182, 185);
    DeployNumber.print("5");
    tft.setCursor(200,185);
    DeployMode.print("BUILD");
}

void GetEngineMode()
{
    tft.setFreeFont(C15B);
    tft.setCursor(205,220);
    EngineMode.print("RACE");
}

void GetBattery(char batt[3])
{
    tft.setFreeFont(C7);
    tft.setCursor(172,250);
    Batt.print("BATT:-");
    tft.setFreeFont(C20B);
    tft.setCursor(210, 270);
    BattPercent.print(batt);
}

void GetEngineBrake()
{
    tft.setFreeFont(C7);
    tft.setCursor(172,290);
    Eb.print("EB:-");
    tft.setFreeFont(C18B);
    tft.setCursor(232 ,300);
    EbValue.print("10");
}

void GetDelta(char delta[6])
{
    tft.setTextDatum(MR_DATUM);
    tft.setFreeFont(C24B);
    tft.setCursor(47, 88);

    if(delta[0] == '-')
    {
        Delta.setTextColor(TFT_GREEN, TFT_BLACK);
        Delta.print(delta);
        return;
    }
    else
    {
        Delta.setTextColor(TFT_RED, TFT_BLACK);
        Delta.print(delta);
        return;
    }
}

void GetDeploy()
{
    tft.setFreeFont(C12);
    tft.setCursor(12,27);
    Deploy.print("DEPLOY");

    tft.setFreeFont(C18B);
    tft.setCursor(90, 29);
    Deploy.print(4);
}













// void GetGearSync(TFT_eSprite gear1, TFT_eSprite gear2, TFT_eSprite gear3, TFT_eSprite gear4,
//                  TFT_eSprite gear5, TFT_eSprite gear6, TFT_eSprite gear7, TFT_eSprite gear8, TFT_eSprite drs, String state)
// {
//     int x = 116;
//     int y = 0;

//     if (state == "OFF")
//     {
//         drs.fillSprite(TFT_TRANSPARENT);
//         drs.pushSprite(x, y);

//         gear1.fillSprite(TFT_WHITE);
//         gear1.pushSprite(120, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("1", gear1.width() / 2 + 120, gear1.height() / 2 + 3);

//         gear2.fillSprite(TFT_WHITE);
//         gear2.pushSprite(151, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("2", gear2.width() / 2 + 151, gear2.height() / 2 + 3);

//         gear3.fillSprite(TFT_WHITE);
//         gear3.pushSprite(182, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("3", gear3.width() / 2 + 182, gear3.height() / 2 + 3);

//         gear4.fillSprite(TFT_WHITE);
//         gear4.pushSprite(213, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("4", gear4.width() / 2 + 213, gear4.height() / 2 + 3);

//         gear5.fillSprite(TFT_WHITE);
//         gear5.pushSprite(244, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("5", gear5.width() / 2 + 244, gear5.height() / 2 + 3);

//         gear6.fillSprite(TFT_WHITE);
//         gear6.pushSprite(275, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("6", gear6.width() / 2 + 275, gear6.height() / 2 + 3);

//         gear7.fillSprite(TFT_WHITE);
//         gear7.pushSprite(306, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("7", gear7.width() / 2 + 306, gear7.height() / 2 + 3);

//         gear8.fillSprite(TFT_WHITE);
//         gear8.pushSprite(337, 6);
//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString("8", gear8.width() / 2 + 337, gear8.height() / 2 + 3);
//     }

//     else
//     {
//         gear1.fillSprite(TFT_TRANSPARENT);
//         gear1.pushSprite(120, 6);

//         gear2.fillSprite(TFT_TRANSPARENT);
//         gear2.pushSprite(151, 6);

//         gear3.fillSprite(TFT_TRANSPARENT);
//         gear3.pushSprite(182, 6);

//         gear4.fillSprite(TFT_TRANSPARENT);
//         gear4.pushSprite(213, 6);

//         gear5.fillSprite(TFT_TRANSPARENT);
//         gear5.pushSprite(244, 6);

//         gear6.fillSprite(TFT_TRANSPARENT);
//         gear6.pushSprite(275, 6);

//         gear7.fillSprite(TFT_TRANSPARENT);
//         gear7.pushSprite(306, 6);

//         gear8.fillSprite(TFT_TRANSPARENT);
//         gear8.pushSprite(337, 6);
        
//         drs.fillSprite(TFT_GREEN);
//         drs.pushSprite(x, y);

//         tft.setFreeFont(C18B);
//         tft.setTextColor(TFT_BLACK);
//         tft.setTextDatum(MC_DATUM);
//         tft.drawString(state, drs.width() / 2 + x, drs.height() / 2 + y);
//     }
// }
