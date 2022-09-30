
# Matt Borek (z1951125)
# Assignment 09
# 04/11/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: bst

bst: bst.cc bst.h binarysearchtree.h btree.h node.h 
	$(CXX) $(CXXFLAGS) -o $@ bst.cc

.PHONY: clean
clean:
	rm -f bst *.o
