
# Matt Borek (z1951125)
# Assignment 04
# 02/15/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: stack

stack: main.cc stack.h rational.cc rational.h
	$(CXX) $(CXXFLAGS) -o $@ main.cc rational.cc 

.PHONY: clean
clean:
	rm -f stack
