## branch TFTILI934

# Connect IO Raspberry

TFTILI934*  |   PI or
    MISO  ----- MISO
    LED   ----- GPIO18
    SCK   ----- SCK
    MOSI  ----- MOSI
    DC    ----- GPIO24
    RESET ----- GPIO25
    CS    ----- CEO -- pin24
    GND   ----- GND
    VCC   ----- 3v3

https://www.xgadget.de/anleitung/2-2-spi-display-ili9341-am-raspberry-betreiben/
https://www.youtube.com/watch?v=3vuK5w8o8dg
## 
# Connect IO Orangepi

                    // define pin usr space
                    //  WPI | Physical | SYS
#define DC_Pin   1  //  0   |   11     | PA1-1
#define RST_Pin  0  //  2   |   13     | PA0-0
#define CS_Pin  67  // 10   |   24     | PC3-
#define LED_Pin  3  //  3   |   15     | PA3-3
# Connect IO Raspberry 
#define DC_Pin   24  //  0   |   11     | PA1-1
#define RST_Pin  25  //  2   |   13     | PA0-0
#define CS_Pin   8   // 10    |   24    | PC3-
#define LED_Pin  18  //  3   |   15     | PA3-3
