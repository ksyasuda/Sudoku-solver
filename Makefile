CXX = g++

CXXFLAGS = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic -DNDEBUG -O3 

DEBUG = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic -DDEBUG -g3
	
all: solver debug

BIN = solver

HEADERS = $(shell find headers -name *.h)

SRCS = $(shell find src -name *.cpp)

all: $(BIN) debug

$(BIN): $(HEADERS) $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

debug: $(HEADERS) $(SRCS)
	$(CXX) $(DEBUG) $^ -o $(BIN)_$@

.PHONY: clean all
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump solver *_debug

