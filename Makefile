CXX = g++

CXXFLAGS = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic -g3 

	
solver: main.cpp board.h board.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


.SUFFIXES:

.PHONY: clean all
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump solver

