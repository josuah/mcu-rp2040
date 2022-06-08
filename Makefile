CFLAGS = -Wall -Wextra -Wconversion -std=c99 -pedantic -ggdb
OBJ = example.o
SDK = .
include ${SDK}/Makefile.inc
flash: flash.mount
