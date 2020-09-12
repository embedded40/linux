/*
 ============================================================================
 Name        : main.c
 Author      : chuongtd4
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

unsigned  pin_no =108;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#include "gpio.h"


int command(char* command_line) {
    char command[50];
    strcpy(command, command_line);
    system(command);
}


int main(void) {
    puts("______Name        : linux_app.cs"); /* prints helloword */
    puts("______Author      : chuongtd4");
    puts("______Version     : v1.0");


        int i = 20;

        gpio_export(pin_no);

        gpio_dir_out( pin_no  );

        while(i--) {

                gpio_value( pin_no  , i & 1); //toggle on GPF0

                //sleep(1);

        }

        gpio_unexport( pin_no  );




}
