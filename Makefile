CC = g++
FLAGS = -std=c++14 -Wall -Wextra -pedantic
OBJ = main.o utils.o #lexer.o

FILES = $*.cpp $*.h

all: $(OBJ)
	$(CC) $(OBJ) -o main

$.cpp: $(FILES)
	g++ -c $(FILES)

clean:
	rm *o main
