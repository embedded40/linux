/*
 ============================================================================
 Name        : main.c
 Author      : chuongtd4
 Version     :
 Copyright   : Your copyright notice
 Description : gpio C, Ansi-style
 ============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif



#ifndef GPIO_H
#define GPIO_H

#define  GPIO_PIN_RESET 0
#define  GPIO_PIN_SET 1

int gpio_export(unsigned gpio);  //Hàm export pin ra user space

int gpio_unexport(unsigned gpio); //Hàm giải phóng pin khi không còn sử dụng

int gpio_dir_out(unsigned gpio); //Cấu hình pin là output

int gpio_dir_in(unsigned gpio); //Cấu hình pin là input

int gpio_value(unsigned gpio, unsigned value); //Đọc/ghi giá trị của pin gpio
int gpioRead(int gpio);

#ifdef __cplusplus
}
#endif


#endif
