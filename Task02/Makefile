CXXFLAGS = -Wall -pedantic -O3
LDFLAGS = -s

TARGETS = Queue.x Radix.x

QUEUE_SOURCES = Queue.cpp
RADIX_SOURCES = Radix.cpp


STACK_OBJECTS = $(STACK_SOURCES:.cpp=.o)
RADIX_OBJECTS = $(RADIX_SOURCES:.cpp=.o)

HEADERS = ArrayQueue.hpp LinkedQueue.hpp


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])

.PHONY: all clean


