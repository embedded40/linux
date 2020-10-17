//cc -o test_fps test_fps.c fontx.c ili9340.c -lwiringPi -lm -lpthread -DSPI -DWPI
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "ili9340.h"

time_t elapsedTime(struct timeval startTime, struct timeval endTime) {
    time_t diffsec = difftime(endTime.tv_sec, startTime.tv_sec);
    suseconds_t diffsub = endTime.tv_usec - startTime.tv_usec;
//printf("diffsec=%ld diffsub=%ld\n",diffsec, diffsub);
    if(diffsub < 0) {
        diffsec--;
        diffsub = (endTime.tv_usec+1000000) - startTime.tv_usec;
    }
    uint16_t diffmsec = diffsub / 1000;
    time_t diff = (diffsec * 1000) + diffmsec;
    return diff;
}
void main()
{
    lcdInit(240, 320, 0, 0);
    lcdReset();
    lcdSetup();
    lcdFillScreen(BLUE);

    FontxFile fx16G[4];
    Fontx_init(fx16G,"./fontx/ILGH32XB.FNT","./fontx/ILGZ32XB.FNT"); // 16x32Dot Gothic

    uint8_t ascii[10];
  //  lcdDrawFillArrow(0, 0, 0, 0, 5, GREEN);
    strcpy((char *)ascii, "test lcd\n");
    lcdDrawUTF8String(fx16G, 50, 300, ascii, GREEN);

    struct timeval startTime, endTime;
    gettimeofday(&startTime, NULL);
    strcpy((char *)ascii, "a");
 for(int i=0;i<1000;i++)
 {

        lcdDrawUTF8String(fx16G, 0, 200,ascii, BLACK);
      //  printf("a\r\n");
    }
 gettimeofday(&endTime, NULL);
 time_t diff = elapsedTime(startTime, endTime);
 printf("%s elapsed time[ms]=%ld\n",__func__, diff);



}
