CXXFLAGS := -Wall -pedantic -O3
LDFLAGS := -s


TARGETS := BinaryTree.x

BINARYTREE_SOURCES := BinaryTree.cpp

BINARYTREE_OBJECTS := $(BINARYTREE_SOURCES:.cpp=.o)


all: $(TARGETS)


%.x: %.o $(HEADERS)
	$(CXX) $(LDFLAGS) -o $@ $<


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(wildcard *.[ox])


.PHONY: all clean tar


