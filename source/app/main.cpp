/*
 ============================================================================
 Name        : main.cpp
 Author      : https://www.facebook.com/embedded.4.0/
 Version     :
 Copyright   : Your copyright notice
 Description : rs232 in c , Ansi-style
 ============================================================================
 */

unsigned  pin_no =108;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"
#include "rs232.h"
#include "gpio.h"
#include "ILI9341_GFX.h"
#include "snow_tiger.h"

int main() {
    puts("______Name        : rs232");
    puts("______Author      : embedded4.0");
    puts("______Version     : v1.0");


    ILI9341_Init();
    HAL_Delay(10);

    ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);

    HAL_Delay(10);
    ILI9341_Image((const char*)snow_tiger,0,0,240,320, SCREEN_HORIZONTAL_2);

}
