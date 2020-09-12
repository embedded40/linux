CXXFLAGS += -I./source/driver/libSSD1306/lib

VPATH += source/driver/libSSD1306/lib

OBJ += $(OBJ_DIR)/OledPixel.o
OBJ += $(OBJ_DIR)/OledI2C.o
OBJ += $(OBJ_DIR)/OledGraphics.o
OBJ += $(OBJ_DIR)/OledHardware.o
OBJ += $(OBJ_DIR)/OledFont8x12.o
OBJ += $(OBJ_DIR)/OledFont8x16.o
OBJ += $(OBJ_DIR)/FileDescriptor.o





