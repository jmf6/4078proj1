CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = voter.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch core main
