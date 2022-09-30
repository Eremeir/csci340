
# Matt Borek (z1951125)
# Assignment 06
# 03/10/2022
# I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic

all: parking

parking: parking.o car.o garage.o
	$(CXX) $(CXXFLAGS) -o $@ parking.o car.o garage.o

parking.o: parking.cc
	$(CXX) $(CXXFLAGS) -c -o $@ parking.cc

car.o: car.cc car.h
	$(CXX) $(CXXFLAGS) -c -o $@ car.cc 

garage.o: garage.cc garage.h
	$(CXX) $(CXXFLAGS) -c -o $@ garage.cc 

.PHONY: clean
clean:
	rm -f parking *.o
