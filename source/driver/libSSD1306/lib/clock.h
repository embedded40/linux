#ifndef CLOCK_H
#define CLOCK_H
#include <array>
#include <chrono>
#include <cmath>
#include <csignal>
#include <cstring>
#include <exception>
#include <iostream>
#include <memory>
#include <thread>
#include <system_error>

#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#include "OledFont8x8.h"
#include "OledFont8x16.h"
#include "OledI2C.h"
void
showTime(
    SSD1306::OledI2C& oled);
#endif // CLOCK_H
