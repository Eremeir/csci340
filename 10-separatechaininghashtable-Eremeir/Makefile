
# Matt Borek (z1951125)
# Assignment 10
# 04/18/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: hash

hash: hashmain.o htable.o
	$(CXX) $(CXXFLAGS) -o $@ hashmain.o htable.o

hashmain.o: hashmain.cc hashmain.h
	$(CXX) $(CXXFLAGS) -c -o $@ hashmain.cc

htable.o: htable.cc htable.h entry.h
	$(CXX) $(CXXFLAGS) -c -o $@ htable.cc 

.PHONY: clean
clean:
	rm -f hash *.o
