CC = g++
CFLAGS = -O3 -std=c++11
INC = -I./
LIB = -L./

TARGET = tool

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

SOURCES = $(wildcard *.c *.cpp)

OBJS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))

all:$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:                             
	rm -rf *.o $(TARGET)
