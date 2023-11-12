CXXFLAGS := -Wall -pedantic -O3
LDFLAGS := -s


TARGETS := ArrayList.x 

ARRAYLIST_SOURCES := LinkedList.cpp

ARRAYLIST_OBJECTS := $(ARRAYLIST_SOURCES:.cpp=.o)


HEADERS := $(wildcard *.hpp)


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])


.PHONY: all clean tar


