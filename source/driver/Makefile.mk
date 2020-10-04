include source/driver/ili9340/Makefile.mk
CXXFLAGS += -I./source/driver

VPATH += source/driver

OBJ += $(OBJ_DIR)/gpio.o
OBJ += $(OBJ_DIR)/rs232.o
