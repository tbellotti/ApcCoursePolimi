
# We want to be verbose "-Wall"
# and to use the c++11 standard "-std=c++11"
CXXFLAGS = -Wall
CXXFLAGS += -std=c++11
# This is the final executable we want
# to obtain from the "make"
EXE = test
# These are the object files we plan to create
# during the make process
OBJECTS = polynomial_function.o bisection.o newton.o test.o

# NB: You have to add the clean in order to
# perform this operation when finished.
all : $(EXE)

$(EXE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXE)

test.o : polynomial_function.o bisection.o newton.o
	$(CXX) $(CXXFLAGS) test.cpp -c -o test.o

polynomial_function.o : polynomial_function.h polynomial_function.cpp
	$(CXX) $(CXXFLAGS) polynomial_function.cpp -c -o polynomial_function.o 

bisection.o : bisection.h bisection.cpp polynomial_function.h
	$(CXX) $(CXXFLAGS) bisection.cpp -c -o bisection.o 

newton.o : newton.h newton.cpp polynomial_function.h
	$(CXX) $(CXXFLAGS) newton.cpp -c -o newton.o 

clean :
	$(RM) *.o

distclean : clean
	$(RM) $(EXE)

 		
