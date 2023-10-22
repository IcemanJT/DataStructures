CXXFLAGS = -Wall -pedantic -O3
LDFLAGS = -s

TARGETS = Queue.x Generator.x 

QUEUE_SOURCES = Queue.cpp
GENERATOR_SOURCES = Generator.cpp


STACK_OBJECTS = $(STACK_SOURCES:.cpp=.o)
GENERATOR_OBJECTS = $(GENERATOR_SOURCES:.cpp=.o)

HEADERS = ArrayQueue.hpp LinkedQueue.hpp


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])

.PHONY: all clean


