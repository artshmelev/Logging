CC=g++
CFLAGS=-std=c++11 -pthread
MKDIR_P=mkdir -p bin

all: dirs
	$(CC) $(CFLAGS) -Iinclude examples/example1.cpp src/*.cpp include/*.h \
										-o bin/example1

dirs:
	$(MKDIR_P)

clean:
	rm -rf bin
