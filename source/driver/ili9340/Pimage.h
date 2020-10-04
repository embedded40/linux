#ifndef PIMAGE_H
#define PIMAGE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

class PImage {
public:
  PImage() :
    _valid(false),
    _bmpWidth(0),
    _bmpHeight(0) { }

  void draw(Adafruit_GFX & glcd, int16_t x, int16_t y);

  static PImage loadImage(const char * fileName);

  void close() { _bmpFile.close(); }

  bool isValid() { return _valid; }

  int width() { return _bmpWidth; }
  int height() { return _bmpHeight; }

private:
  friend class Adafruit_GFX;

  File _bmpFile;
  int  _bmpWidth, _bmpHeight;   // W+H in pixels
  uint8_t  _bmpDepth;              // Bit depth (currently must be 24)
  uint32_t _bmpImageoffset;        // Start of image data in file
  uint32_t _rowSize;               // Not always = bmpWidth; may have padding
  bool     _flip;

  bool     _valid;

  PImage(File & bmpFile, int bmpWidth, int bmpHeight, uint8_t  bmpDepth, uint32_t bmpImageoffset, uint32_t rowSize, bool     flip) :
  _bmpFile(bmpFile),
  _bmpWidth(bmpWidth),
  _bmpHeight(bmpHeight),
  _bmpDepth(bmpDepth),
  _bmpImageoffset(bmpImageoffset),
  _rowSize(rowSize),
  _flip(flip),
  _valid(true) // since Adafruit_GFX is friend, we could just let it write the variables and save some CPU cycles
  { }

  static uint16_t read16(File f);
  static uint32_t read32(File f);

  // TODO close the file in ~PImage and PImage(const PImage&)

};

#endif

#endif // _PIMAGE_H
#endif // PIMAGE_H
