#-include source/driver/libSSD1306/lib/Makefile.mk
CXXFLAGS += -I./source/driver

VPATH += source/driver

OBJ += $(OBJ_DIR)/gpio.o
OBJ += $(OBJ_DIR)/rs232.o
