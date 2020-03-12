#include <iostream>
#include <fstream>
#include <cmath>
#include "../headers/board.h"

Board::Board(int size_) {
    	size = size_;
	board.resize(size_);
	for(int i = 0; i < size_; ++i) {
		board[i].resize(size_);
	}
}

void Board::printBoard() {
	std::cout << "-------------------------------------\n";
	for(int i = 0; i < getSize(); ++i) {
		for(int j = 0; j < getSize(); ++j) {
			if(j == getSize()-1) std::cout << "| " << board[i][j] << " |\n";
			else std::cout << "| " << board[i][j] << " ";
		}
		// std::cout << "\n";
		std::cout << "-------------------------------------\n";
	}
	std::cout << "\n";
}

void Board::printOutput() {
#ifdef DEBUG
	std::cout << count << " recursive calls\n";
#endif
	std::cout << "-------------------------------------\n";
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(j == getSize()-1) std::cout << "| " << output_board[i][j] << " |\n";
			else std::cout << "| " << output_board[i][j] << " ";
		}
		// std::cout << "\n";
		std::cout << "-------------------------------------\n";
	}
	std::cout << "\n";
}

int Board::getSize() {
	return size;
}

void Board::setBoard(int x, int y, int n) {
	board[x][y] = n;
}

void Board::readBoard(std::ifstream& is) {
	int num;
	int count=0;
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			is >> num;
			board[i][j] = num;
			++count;
		}
	}
	if(count != size*size) {
		std::cerr << "Must input a valid board\n";
		exit(1);
	}
}

void Board::solve() {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(board[i][j] == 0) {
			for(int k = 1; k <= 9; k++) {
				if(findMove(i, j, k)) {
				board[i][j] = k;
				#ifdef DEBUG
				++count;
				printBoard();
				#endif
				solve();
				board[i][j] = 0;
				}
			}
			//* board not valid
			return;
			}
		}
    }
    // std::cout << "NICE\n";
	copyBoard();
    return;
}

void Board::copyBoard() {
	//* set up output board for copy
	output_board.resize(size);
	for(size_t i = 0; i < output_board.size(); ++i) {
		output_board[i].resize(size);
	}
	//* copy values from board to output
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			output_board[i][j] = board[i][j];
		}
	}
}

bool Board::findMove(int row, int col, int k) {
	// if the row has k already return false	
	for(int i = 0; i < size; ++i) {
		if(board[row][i] == k) return false;
	}
	// if the col has k already return false
	for(int i = 0; i < size; ++i) {
		if(board[i][col] == k) return false;
	}
	//* change the row and col to start at the beginning of each square
	int trow = (row/3) * 3;
	int tcol = (col/3) * 3;
	// if the current square already has k then return false
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(board[trow+i][tcol+j] == k) return false;
		}
	}
	return true;
}
