include source/driver/ILI9341/Makefile.mk
CXXFLAGS += -I./source/driver

VPATH += source/driver

OBJ += $(OBJ_DIR)/gpio.o
OBJ += $(OBJ_DIR)/rs232.o
OBJ += $(OBJ_DIR)/spi.o
