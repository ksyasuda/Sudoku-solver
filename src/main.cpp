#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "../headers/board.h"


int main(int argc, char* argv[]) {
	// int size = 12;
	// int size = 9;
	//int size = 6;
	if(argc < 3) {
		std::cerr << "Must input a valid sudoku board\n";
		exit(1);
	}
	std::string file = argv[2];
	std::ifstream is(file, std::ifstream::in);
	if(!is.is_open()) {
		std::cerr << "Not open\n";
	}
	int size = atoi(argv[1]);
	Board board(size);
	board.readBoard(is);
	std::cout << board.colors[0] << "            Input board\n";
	board.printBoard();
	std::cout << board.colors[5] << "            Solved board\n";
	board.solve();
	// board.printBoard();
	board.printOutput();
	return 0;
}
