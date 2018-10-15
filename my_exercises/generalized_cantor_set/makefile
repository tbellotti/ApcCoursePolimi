CXXFLAGS += -Wall
CXXFLAGS += -std=c++11
EXE = cantorTest
OBJECTS = segment.o cantorset.o

.phony : all clean

all : $(EXE)

$(EXE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXE)

segment.o : segment.h
cantorset.o : cantorset.h

clean:
	$(RM) *.o

distclean : clean
	$(RM) $(EXE)


