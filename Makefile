CC=gcc

SRC = src/time.c
BIN = src/time

all: ${BIN}

BIN: ${SRC}

clean:
	${RM} *.o ${BIN}

.PHONY: all, clean