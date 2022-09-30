
# Matt Borek (z1951125)
# Assignment 07
# 03/21/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: wordscanner

wordscanner: wordscanner.cc
	$(CXX) $(CXXFLAGS) -o $@ wordscanner.cc

.PHONY: clean
clean:
	rm -f wordscanner *.o
