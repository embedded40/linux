
#ifdef __cplusplus
extern "C" {
#endif


#ifndef ILI9341_STM32_DRIVER_H
#define ILI9341_STM32_DRIVER_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define SYS

#ifdef WPI
#include <wiringPi.h>
#include <wiringPiSPI.h>
#else
#include "../spi.h"
#include "../gpio.h"
#endif

#ifdef WPI
//  WPI | Physical | SYS

#define DC_Pin   0  //  0   |   11     | PA1-1
#define RST_Pin  2  //  2   |   13     | PA0-0
#define CS_Pin  10  // 10   |   24     | PC3-
#define LED_Pin  3  //  3   |   15     | PA3-3


#else
                    // define pin usr space
                    //  WPI | Physical | SYS
#define DC_Pin   1  //  0   |   11     | PA1-1
#define RST_Pin  0  //  2   |   13     | PA0-0
#define CS_Pin  67  // 10   |   24     | PC3-
#define LED_Pin  3  //  3   |   15     | PA3-3

//PC0 GPIO64
#define SPI_DEVICE "/dev/spidev0.0"
#define SPI_SPEED  48000000
extern spi_t HSPI_INSTANCE;
#endif


#ifdef WPI
#define gpio_value digitalWrite
#define GPIO_PIN_RESET 0
#define GPIO_PIN_SET   1
#endif




#define ILI9341_SCREEN_HEIGHT   240
#define ILI9341_SCREEN_WIDTH 	320


#define LCD_CS_PIN								CS_Pin
#define LCD_DC_PIN								DC_Pin
#define	LCD_RST_PIN								RST_Pin
#define	LCD_LED_PIN								LED_Pin




#define BURST_MAX_SIZE 	500

#define BLACK       0x0000      
#define NAVY        0x000F      
#define DARKGREEN   0x03E0      
#define DARKCYAN    0x03EF      
#define MAROON      0x7800      
#define PURPLE      0x780F      
#define OLIVE       0x7BE0      
#define LIGHTGREY   0xC618      
#define DARKGREY    0x7BEF      
#define BLUE        0x001F      
#define GREEN       0x07E0      
#define CYAN        0x07FF      
#define RED         0xF800     
#define MAGENTA     0xF81F      
#define YELLOW      0xFFE0      
#define WHITE       0xFFFF      
#define ORANGE      0xFD20      
#define GREENYELLOW 0xAFE5     
#define PINK        0xF81F

#define SCREEN_VERTICAL_1			0
#define SCREEN_HORIZONTAL_1		1
#define SCREEN_VERTICAL_2			2
#define SCREEN_HORIZONTAL_2		3
void HAL_Delay(uint32_t tms );
void ILI9341_SPI_Init(void);
void ILI9341_SPI_Send(unsigned char SPI_Data);
void ILI9341_Write_Command(uint8_t Command);
void ILI9341_Write_Data(uint8_t Data);
void ILI9341_WriteData(uint8_t* buff, size_t buff_size);
void ILI9341_Set_Address(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2);
void ILI9341_Reset(void);
void ILI9341_Set_Rotation(uint8_t Rotation);
void ILI9341_Enable(void);
void ILI9341_Init(void);
void ILI9341_Fill_Screen(uint16_t Colour);
void ILI9341_Draw_Colour(uint16_t Colour);
void ILI9341_Draw_Pixel(uint16_t X,uint16_t Y,uint16_t Colour);
void ILI9341_Draw_Colour_Burst(uint16_t Colour, uint32_t Size);


void ILI9341_Draw_Rectangle(uint16_t X, uint16_t Y, uint16_t Width, uint16_t Height, uint16_t Colour);
void ILI9341_Draw_Horizontal_Line(uint16_t X, uint16_t Y, uint16_t Width, uint16_t Colour);
void ILI9341_Draw_Vertical_Line(uint16_t X, uint16_t Y, uint16_t Height, uint16_t Colour);

#define TFT_DEBUG

#ifdef TFT_DEBUG
#  include <stdio.h>  // fprintf()
#    define TFT_DBG(fmt, arg...) fprintf(stderr, "SPI: " fmt "\n", ## arg)
#else
#  define TFT_DBG(fmt, ...) // debu
#endif

#endif

#ifdef __cplusplus
}
#endif
