
# Matt Borek (z1951125)
# Assignment 08
# 04/7/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: binarytree

binarytree: binarytree.cc btree.h node.h 
	$(CXX) $(CXXFLAGS) -o $@ binarytree.cc

.PHONY: clean
clean:
	rm -f binarytree *.o
