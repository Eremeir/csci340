
# Matt Borek (z1951125)
# Assignment 11
# 04/26/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: simplegraph

simplegraph: simplegraph.o graph.o
	$(CXX) $(CXXFLAGS) -o $@ simplegraph.o graph.o

simplegraph.o: simplegraph.cc graph.h
	$(CXX) $(CXXFLAGS) -c -o $@ simplegraph.cc

graph.o: graph.cc graph.h
	$(CXX) $(CXXFLAGS) -c -o $@ graph.cc 

.PHONY: clean
clean:
	rm -f simplegraph *.o
