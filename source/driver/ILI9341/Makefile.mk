#============================================================================
# Name        : Makefile.mk
# Author      : chuongtd4
# Date        : 13/04/2020
# https://github.com/martnak/STM32-ILI9341
# ============================================================================

CXXFLAGS += -I./source/driver/ILI9341
VPATH += source/driver/ILI9341

OBJ += $(OBJ_DIR)/fonts.o
OBJ += $(OBJ_DIR)/ILI9341_GFX.o
OBJ += $(OBJ_DIR)/ILI9341_OP_Driver.o
