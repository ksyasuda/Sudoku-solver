#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <fstream>

constexpr auto RED = "\033[31m";
constexpr auto GREEN = "\033[32m";
constexpr auto YELLOW = "\033[33m";
constexpr auto BLUE = "\033[34m";
constexpr auto WHITE = "\033[90m";
constexpr auto ORANGE = "\033[96m";
constexpr auto BLACK = "\033[93m";
constexpr auto PURPLE = "\033[95m";
constexpr auto CYAN = "\033[36m";
constexpr auto RESET = "\033[0m";

class Board {
public:
	std::vector<std::vector<int>> board;
	std::vector<std::vector<int>> output_board;
	std::vector<std::vector<int>> board_copy;
	const char* colors[11] = {RED, ORANGE, YELLOW, GREEN, BLUE, CYAN, PURPLE, BLACK,
	WHITE, RESET };
	int size;
	int remaining_squares = 0;
	int count = 0;
	bool solved = false;

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
