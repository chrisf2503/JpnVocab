OBJECTS= main.o 
NOTES = notes.o
TEST = test.o
DOCTEST = doctest.o
CXXFLAGS= -g3
LDFLAGS=
CXX=g++
EXE=main notes test doctest
main: $(OBJECTS)
	$(CXX) -g -o main $(OBJECTS)

notes: $(NOTES)
	$(CXX) -g -o notes $(NOTES)

test: $(TEST)
	$(CXX) -g -o test $(TEST)

doctest: $(DOCTEST)
	$(CXX) -g -o doctest $(DOCTEST)

main.o: main.cpp flashCard.h

notes.o: notes.cpp

test.o: test.cpp flashCard.h VocabTree.h

doctest.o: doctest.cpp doctest.h flashCard.h VocabTree.h KanjiList.h word.h

clean:
	rm -f $(OBJECTS) $(TEST) $(DOCTEST) $(NOTES) $(EXE)