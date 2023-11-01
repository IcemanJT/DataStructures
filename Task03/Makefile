CXXFLAGS := -Wall -pedantic -O3
LDFLAGS := -s


TARGETS := LinkedList.x 

LINKEDLIST_SOURCES := LinkedList.cpp

LINKEDLIST_OBJECTS := $(LINKEDLIST_SOURCES:.cpp=.o)


HEADERS := $(wildcard *.hpp)


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])


.PHONY: all clean tar


