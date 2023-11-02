CXXFLAGS := -Wall -pedantic -O3
LDFLAGS := -s


TARGETS := LinkedList.x Generator.x

LINKEDLIST_SOURCES := LinkedList.cpp
GENERATOR_SOURCES := Generator.cpp

LINKEDLIST_OBJECTS := $(LINKEDLIST_SOURCES:.cpp=.o)
GENERATOR_SOURCES := $(GENERATOR_SOURCES:.cpp=.o)


HEADERS := $(wildcard *.hpp)


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])


.PHONY: all clean tar


