CC = g++

CFLAGS = -Wall -Wextra -std=c++11 -O3 -g

.PHONY: all clean

all: PCP

PCP: main.o
	$(CC) $(CFLAGS) $^ -o PCP

main.o: main.cpp

clean:
	rm *.o
