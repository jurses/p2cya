CC=g++
CFLAGS=-g

all: language.o alphabet.o word.o
	$(CC) -o calc.out

word:
	$(CC) 