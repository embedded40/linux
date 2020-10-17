1. Raspberry

#define D_C  3  //  0   |   11     | PA1-1
#define RES  2  //  2   |   13     | PA0-0
#define C_S  10 // 10   |   24     | PC3-
#define LED  0  //  3   |   15     | PA3-3

2. Biên dịch 
cc -o demo_basic demo_basic.c fontx.c ili9340.c -lwiringPi -lm -lpthread -DSPI -DWPI


3. Chạy file thực thi

./demo_basic
