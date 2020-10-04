#============================================================================
# Name        : Makefile.mk
# Author      : chuongtd4
# Date        : 13/04/2020
# ============================================================================

CXXFLAGS += -I./source/driver/ili9340
VPATH += source/driver/ili9340
OBJ += $(OBJ_DIR)/fontx.o
#OBJ += $(OBJ_DIR)/xpt2046.o
OBJ += $(OBJ_DIR)/ili9340.o
#OBJ += $(OBJ_DIR)/xpt.o
