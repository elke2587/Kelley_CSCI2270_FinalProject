
CXX = g++
CXXFLAGS = -Wall -Werror
OBJ = ColoradoRiver.o Diversions.o
OUT = ColoradoRiver.out

all : program

program : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)

ColoradoRiver.o : ColoradoRiver.cpp Diversions.h
	$(CXX) $(CXXFLAGS) -c ColoradoRiver.cpp

Diversions.o : Diversions.cpp Diversions.h
	$(CXX) $(CXXFLAGS) -c Diversions.cpp

clean :
	rm *.o

uninstall :
	rm *.out

