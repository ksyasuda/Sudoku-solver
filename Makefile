CXX = g++

CXXFLAGS = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic -DNDEBUG -O3 

DEBUG = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic -DDEBUG -g3
	

all: solver debug

solver: src/main.cpp headers/board.h src/board.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

debug: src/main.cpp headers/board.h src/board.cpp
	$(CXX) $(DEBUG) $^ -o solver_$@

.SUFFIXES:

.PHONY: clean all
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump solver *_debug

