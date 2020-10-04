//cc -o demo_basic demo_basic.c fontx.c ili9340.c -lwiringPi -lm -lpthread -DSPI -DWPI
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "ili9340.h"


void main()
{
    lcdInit(240, 320, 0, 0);
    lcdReset();
    lcdSetup();
    lcdFillScreen(RED);

    FontxFile fx16G[4];
    Fontx_init(fx16G,"./fontx/ILGH32XB.FNT","./fontx/ILGZ32XB.FNT"); // 16x32Dot Gothic

    uint8_t ascii[10];
  //  lcdDrawFillArrow(0, 0, 0, 0, 5, GREEN);
    strcpy((char *)ascii, "test lcd");
    lcdDrawUTF8String(fx16G, 0, 0, ascii, GREEN);

    while(1)
    {
        strcpy((char *)ascii, "test lcd\r\n");
        lcdDrawUTF8String(fx16G, 0, 15, ascii, GREEN);
    }

}
