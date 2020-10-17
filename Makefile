
###############################################################
#author  : chuongtd4
#date    : 25/02/2019
#########################chuongtd4#############################

LGB             = ./scrip/logo.sh

RPI_SYS_DIR	=
TOOLS_DIR	=
NAME_MODULE	= tft
CXX		= arm-linux-gnueabihf-g++
CC		= arm-linux-gnueabihf-gcc
#CXX=g++
#CC=gcc
OBJ_DIR		= build_$(NAME_MODULE)

OPTIMIZE_OPTION	=	-g
WARNNING_OPTION	+=      -Wall -W -Wno-missing-field-initializers
-include source/app/Makefile.mk
-include source/driver/Makefile.mk

CFLAGS	+= -I/usr/local/include
CFLAGS	+= -I/usr/include

CXXFLAGS	+= -I/usr/local/include
CXXFLAGS	+= -I/usr/include
 
# CXX compiler option
CXXFLAGS	+=	$(OPTIMIZE_OPTION)	\
                $(WARNNING_OPTION)	\
                -std=c++11		\
                -Wall			\
                -Winline		\
                -pipe			\
                -g			\
                -DSPI -DWPI		\

# Library paths
LDFLAGS	+= -L/usr/local/lib
LDFLAGS	+= -L/usr/include
LDFLAGS	+= -Wl,-Map=$(OBJ_DIR)/$(NAME_MODULE).map

#Library libs
LDLIBS	+=	-lpthread		\
		-lrt			\
		-lm			\

all: create $(OBJ_DIR)/$(NAME_MODULE)
create:
	@bash ./scrip/logo.sh
	@echo mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@echo ---------- c++ compiler ----------
	@echo CXX $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
$(OBJ_DIR)/%.o: %.cxx
	@echo ---------- c++ compiler ----------
	@echo CXX $<
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: %.c
	@echo ---------- c   compiler ----------
	@echo CXX $<
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/$(NAME_MODULE): $(OBJ)
	@echo ------- START LINK PROJECT --------
	@echo $(CXX) -o $@ $^ $(CXXFLAGS)
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

.PHONY: copy
copy:
	@echo ------------ copy app ------------
#	scp -r ./build_linux_app/linux_app root@192.168.10.22:/root
	sshpass -p raspberry scp build_*/$(NAME_MODULE) pi@192.168.1.9:/home/pi

.PHONY: flash
flash:
	@sudo LD_LIBRARY_PATH=/usr/local/lib/ $(OBJ_DIR)/$(NAME_MODULE)

.PHONY: debug
debug:
	sudo gdb $(OBJ_DIR)/$(NAME_MODULE)

.PHONY: install
install:
	cp $(OBJ_DIR)/$(NAME_MODULE) /usr/local/bin

.PHONY: clean
clean:
	@echo rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)

