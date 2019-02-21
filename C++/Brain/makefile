all: LidarFilter

CC = g++
CXXFLAGS = -std=c++11 -O2
first:
	echo doing $@
second:
	echo doing $@
third:
	echo doing $@
how: first second third
	echo $@
	echo $^
	echo $<
LidarFilter: obj/main.o obj/Test.o obj/MedianFilter.o obj/RangeFilter.o
	$(CC) $(CXXFLAGS) $^ -o $@


obj/main.o: main.cpp RangeFilter.h MedianFilter.h Test.h
	$(CC) $(CXXFLAGS) -c $< -o $@

obj/Test.o: Test.cpp Test.h RangeFilter.h
	$(CC) $(CXXFLAGS) -c $< -o $@

obj/MedianFilter.o: MedianFilter.cpp MedianFilter.h RangeFilter.h
	$(CC) $(CXXFLAGS) -c $< -o $@

obj/RangeFilter.o: RangeFilter.cpp RangeFilter.h
	$(CC) $(CXXFLAGS) -c $< -o $@