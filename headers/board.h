#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <fstream>

class Board {
public:
	std::vector<std::vector<int>> board;
	std::vector<std::vector<int>> output_board;
	int size;
	int remaining_squares = 0;
	int count = 0;

	Board(int size);

	void printBoard();

	void printOutput();

	int getSize();

	void setBoard(int x, int y, int n);

	void solve();

	bool findMove(int row, int col, int k);

	void readBoard(std::ifstream& is);

	void copyBoard();
};
#endif
