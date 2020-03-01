#include <iostream>
#include "board.h"
#include <fstream>
#include <cmath>

Board::Board(int size_) : size{size_} {
	board.resize(size_);
	for(int i = 0; i < size_; ++i) {
		board[i].resize(size_);
	}
}

void Board::printBoard() {
	for(int i = 0; i < getSize(); ++i) {
		for(int j = 0; j < getSize(); ++j) {
			if(j == getSize()-1) std::cout << "| " << board[i][j] << " |\n";
			else std::cout << "| " << board[i][j] << " ";
		}
		// std::cout << "\n";
	}
}

int Board::getSize() {
	return size;
}

void Board::setBoard(int x, int y, int n) {
	board[x][y] = n;
}

void Board::readBoard(std::ifstream& is) {
	int num;
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			is >> num;
			board[i][j] = num;
		}
	}
}

void Board::solve() {
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(board[i][j] == 0) {
				for(int k = 1; k <= size; ++k) {
					if(findMove(i, j, k)) {
						board[i][j] = k;
						solve();
						board[i][j] = 0;
					}
				}
				return;
			}
		}
	}
}

bool Board::findMove(int row, int col, int k) {
	for(int i = 0; i < size; ++i) {
		if(board[row][i] == k) return false;
	}
	for(int i = 0; i < size; ++i) {
		if(board[i][col] == k) return false;
	}
	//* change the row and col to start at the beginning of each square
	row = (row/3) * 3;
	col = (col/3) * 3;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(board[row+i][col+j] == k) return false;
		}
	}
	return true;
}