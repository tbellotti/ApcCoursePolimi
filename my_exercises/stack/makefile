CXXFLAGS+=-Wall
EXE = stack_test
OBJECTS = stack_test.o

all: stack_test
stack_test : stack_test.o
	g++ $(CXXFLAGS) $(OBJECTS) -o $(EXE)

$(OBJECTS) : stack_test.cpp
	g++ $(CXXFLAGS) stack_test.cpp -c -o $(OBJECTS)

# Add the dependences of stack_test from the libraries I've written... (IMPORTANT)

clean :
	rm -f *.o

distclean :
	rm -f $(EXE)