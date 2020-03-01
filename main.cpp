#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "board.h"


int main(int argc, char* argv[]) {
	// int size = 12;
	int size = 9;
	if(argc > 2 && strcmp(argv[0], "NICE")) exit(1);
	std::ifstream is("test.txt", std::ifstream::in);
	if(!is.is_open()) {
		std::cerr << "Not open\n";
	}
	Board board(size);
	board.readBoard(is);
	// board.printBoard();
	board.solve();
	board.printBoard();
	return 0;
}