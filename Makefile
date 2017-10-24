CC = g++
FLAGS = -std=c++14 -Wall -Wextra -pedantic
OBJ = main.o utils.o scanner.o errorLog.o ast.o parser.o

FILES = $*.cpp $*.h

all: $(OBJ)
	$(CC) $(OBJ) -o main

$.cpp: $(FILES)
	g++ -c $(FILES)

clean:
	rm *o main
