#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <fstream>

class Board {
public:
	std::vector<std::vector<int>> board;
	int size;
	int remaining_squares = 0;

	Board(int size);

	void printBoard();

	int getSize();

	void setBoard(int x, int y, int n);

	void solve();

	bool findMove(int row, int col, int k);

	void readBoard(std::ifstream& is);
};
#endif