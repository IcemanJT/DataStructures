CXXFLAGS := -Wall -pedantic -O3
LDFLAGS := -s


TARGETS := BubbleSort.x InsertionSort.x SelectionSort.x

BUBBLESORT_SOURCES := BubbleSort.cpp
INSERTIONSORT_SOURCES := InsertionSort.cpp
SELECTIONSORT_SOURCES := SelectionSort.cpp


BUBBLESORT_OBJECTS := $(BUBBLESORT_SOURCES:.cpp=.o)
INSERTIONSORT_OBJECTS := $(INSERTIONSORT_SOURCES:.cpp=.o)
SELECTIONSORT_OBJECTS := $(SELECTIONSORT_SOURCES:.cpp=.o)


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])


.PHONY: all clean tar


