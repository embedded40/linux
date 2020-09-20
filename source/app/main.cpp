/*
 ============================================================================
 Name        : main.c
 Author      : https://www.facebook.com/embedded.4.0/
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

unsigned  pin_no =108;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"
#include "gpio.h"



int main(void) {
    puts("______Name        : gpio");
    puts("______Author      : embedded4.0");
    puts("______Version     : v1.0");

        gpio_export(pin_no);

        gpio_dir_out( pin_no  );

        while(1) {

                gpio_value( pin_no  , 1); //toggle on GPF0
                sleep(1);
                gpio_value( pin_no  , 1);
                sleep(0);

        }

        gpio_unexport( pin_no  );




}
