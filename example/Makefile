LDFLAGS = -Wl,-Map=firmware.map
CFLAGS = -Os -g -Wall -Wextra -std=c99 -pedantic
OBJ = main.o

SDK = ..
include ${SDK}/Makefile.mk

all: firmware.elf firmware.asm

flash: flash.mount
