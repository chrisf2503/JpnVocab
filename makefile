OBJECTS= main.o 
TEST = test.o
CXXFLAGS= -g3
LDFLAGS=
CXX=g++

main: $(OBJECTS)
	$(CXX) -g  -o main $(OBJECTS)

test: $(TEST)
	$(CXX) -g -o test $(TEST)

main.o: main.cpp flashCard.h

test.o: test.cpp flashCard.h VocabTree.h

clean:
	rm -f $(OBJECTS) $(TEST)