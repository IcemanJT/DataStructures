CXXFLAGS := -Wall -pedantic -O3
LDFLAGS := -s

TARGETS := Dict.x

SOURCES := Dict.cpp hash_function.cpp
HEADERS := Dict.hpp LinkedList.hpp hash_function.hpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(TARGETS)

Dict.x: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^
	rm *.o
	

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])

.PHONY: all clean
