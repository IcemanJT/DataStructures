CXXFLAGS = -Wall -pedantic -O3
LDFLAGS = -s

TARGETS = Stack.x Generator.x ONP.x

STACK_SOURCES = Stack.cpp
GENERATOR_SOURCES = Generator.cpp
ONP_SOURCES = ONP.cpp

STACK_OBJECTS = $(STACK_SOURCES:.cpp=.o)
GENERATOR_OBJECTS = $(GENERATOR_SOURCES:.cpp=.o)
ONP_OBJECTS = $(ONP_SOURCES:.cpp=.o)

HEADERS = ArrayStack.hpp LinkedStack.hpp


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])

.PHONY: all clean


