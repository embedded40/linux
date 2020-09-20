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



int main(void) {
    puts("______Name        : rs232");
    puts("______Author      : embedded4.0");
    puts("______Version     : v1.0");

   int com1= comFindPort("ttyUSB0");
   if(com1<0) printf("khong tim thay cong nay\n");
   comOpen(com1,9600);


        while(1) {

            comWrite(com1,"LED 1 1\n",8);  //  led on arduino
            sleep(1);
            comWrite(com1,"LED 1 0\n",8);  //  led on arduino
            sleep(1);
        }


}
