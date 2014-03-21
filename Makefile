CC=g++
CFLAGS=-std=c++11

all:
	$(CC) $(CFLAGS) main.cpp logging.cpp logging.h buffer.cpp buffer.h -o main

clean:
	rm -f main
