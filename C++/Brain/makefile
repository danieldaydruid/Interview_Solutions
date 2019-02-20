all: LidarFilter

LidarFilter: main.o Test.o MedianFilter.o RangeFilter.o
	g++ $^ -std=c++11 -O2 -o $@