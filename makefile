OBJECTS= main.o 
TEST = test.o
DOCTEST = doctest.o
CXXFLAGS= -g3
LDFLAGS=
CXX=g++

main: $(OBJECTS)
	$(CXX) -g -o main $(OBJECTS)

test: $(TEST)
	$(CXX) -g -o test $(TEST)

doctest: $(DOCTEST)
	$(CXX) -g -o doctest $(DOCTEST)

main.o: main.cpp flashCard.h

test.o: test.cpp flashCard.h VocabTree.h

doctest.o: doctest.cpp doctest.h flashCard.h VocabTree.h

clean:
	rm -f $(OBJECTS) $(TEST) $(DOCTEST)