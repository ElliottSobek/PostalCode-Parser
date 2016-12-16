CC = g++

CFLAGS = -std=c++11 -Wall -Wextra -O3 -g

.PHONY: all clean

all: PCP

PCP: main.o
	$(CC) $(CFLAGS) $^ -o PCP

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o
