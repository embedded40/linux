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
#include "rs232.h"



int main(void) {
    puts("______Name        : rs232");
    puts("______Author      : embedded4.0");
    puts("______Version     : v1.0");

   int port= comFindPort("/dev/ttyUSB1");
   printf("ret=%d\r\n",port);

   comOpen(port,115200);


        while(1) {

            comWrite(1,"LED 1 1",7);  //  led on arduino
            sleep(1);
            comWrite(1,"LED 1 0",7);  //  led on arduino
            sleep(1);
        }


}
