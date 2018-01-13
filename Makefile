# PostalCode Parser
# Copyright (C) 2016  Author: Elliott Sobek
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

CC = g++

CFLAGS = -std=c++11 -Wall -Wextra -O3 -g

.PHONY: all clean

all: PCP

PCP: main.o menu.o
	$(CC) $(CFLAGS) $^ -o PCP

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

menu.o: menu.cpp
	$(CC) $(CFLAGS) -c menu.cpp

clean:
	rm *.o
