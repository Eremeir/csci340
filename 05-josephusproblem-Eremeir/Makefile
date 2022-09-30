
# Matt Borek (z1951125)
# Assignment 05
# 03/1/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: josephus

josephus: josephus.cc josephus.h
	$(CXX) $(CXXFLAGS) -o $@ josephus.cc

.PHONY: clean
clean:
	rm -f josephus
