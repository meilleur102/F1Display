#include <Arduino.h>
#include <AnimatedGIF.h>
#include <GifDraw.h>
#include "gifData.h"

#define GIF_IMAGE amg //  No DMA  63 fps, DMA:  71fps

AnimatedGIF gif;

extern TFT_eSPI tft;

void GetWelcomeAnim()
{

    gif.begin(BIG_ENDIAN_PIXELS);

    // Put your main code here, to run repeatedly:
    if (gif.open((uint8_t *)GIF_IMAGE, sizeof(GIF_IMAGE), GIFDraw))
    {
        Serial.printf("Successfully opened GIF; Canvas size = %d x %d\n", gif.getCanvasWidth(), gif.getCanvasHeight());
        tft.startWrite(); // The TFT chip slect is locked low
        while (gif.playFrame(true, NULL))
        {
            yield();
        }
        gif.close();
        tft.endWrite(); // Release TFT chip select for other SPI devices
        delay(400);
        tft.fillScreen(TFT_BLACK);
    }
}
