CC=g++

all:
	g++ main.cpp logging.cpp logging.h -o main -std=c++11

clean:
	rm -f main
