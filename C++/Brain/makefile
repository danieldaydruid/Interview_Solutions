all: program

program: main.o test.o MedianFilter.o RangeFilter.o
	g++ $^ -std=c++11 -O2 -o $@