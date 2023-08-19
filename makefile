OBJECTS= main.o 
CXXFLAGS= -g3
LDFLAGS=
CXX=g++

main: $(OBJECTS)
	$(CXX) -g  -o main $(OBJECTS)
main.o: main.cpp flashCard.h

clean:
	rm -f $(OBJECTS)