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
			if(j == getSize()-1) std::cout << "| " << board[i][j]
				<< " |\n";
			else std::cout << "| " << board[i][j] << " ";
		}
		// std::cout << "\n";
		std::cout << "-------------------------------------\n";
	}
	std::cout << "\n";
}

void Board::printOutput() {
#ifdef DEBUG
	std::cout << count << " numbers tried\n";
#endif
	//std::cout << "---------------------------------------\n";
	std::cout << colors[0] << "-------------";
	std::cout << colors[1] << "-------------";
	std::cout << colors[2] << "-------------\n";
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(i >= 0 && i <=2 && j >= 0 && j <=2) {
				if(j == 2) std::cout << colors[0] << "| " << colors[9] <<
					output_board[i][j] << colors[0] << " |";
				else std::cout << colors[0]  << "| " << colors[9] <<
					output_board[i][j] << colors[0] << " ";
			} else if(i >= 0 && i <=2 && j >= 3 && j <=5) {	
				if(j == 5) std::cout << colors[1] << "| " << colors[9] <<
					output_board[i][j] << colors[1] << " |";
				else std::cout << colors[1] << "| " << colors[9] <<  output_board[i][j] << colors[1] << " ";
			} else if(i >= 0 && i <=2 && j <= 8) {
				if(j == size-1) std::cout << colors[2] << "| " << colors[9] <<
					output_board[i][j] << colors[2] << " |\n";
				else std::cout << colors[2] << "| " << colors[9] <<
					output_board[i][j] << colors[2] << " ";
			} else if(i >=3 && i <=5 && j >=0 && j<=2) {
				if(j == 2) std::cout << colors[3] << "| " << colors[9] <<
				   	output_board[i][j] << colors[3] << " |";
				else std::cout << colors[3]  << "| " << colors[9] <<
					output_board[i][j] << colors[3] << " ";
			} else if(i >= 3 && i <=5 && j >=3 && j <= 5) {
				if(j == 5) std::cout << colors[4] << "| " << colors[9] <<
					output_board[i][j] << colors[4] << " |";
				else std::cout << colors[4] << "| " << colors[9] <<
					output_board[i][j] << colors[4] << " ";
			} else if(i >=3 && i <=5 && j <= 8) {
				if(j == 8) {
					std::cout << colors[5] << "| " << colors[9] <<
					output_board[i][j] << colors[5] << " |\n";
				}
				else{
					std::cout << colors[5] << "| " << colors[9] << output_board[i][j] << colors[5] << " ";
				}
			} else if(i>=6 && j >=0 && j <= 2) {
				if(j == 2) std::cout << colors[6] << "| " << colors[9] <<
					output_board[i][j] << colors[6] << " |";
				else std::cout << colors[6] << "| " << colors[9] <<
					output_board[i][j] << colors[6] << " ";
			} else if(i >=6 && j>=3 && j<=5) {
				if(j == 5) std::cout << colors[7] << "| " << colors[9] <<
					output_board[i][j] << colors[7] << " |";
				else std::cout << colors[7] << "| " << colors[9] <<
					output_board[i][j] << colors[7] << " ";
			} else if(i >=6 && j >=6) {
				if(j == 8) std::cout << colors[8] << "| " << colors[9] <<
					output_board[i][j] << colors[8] << " |\n";
				else std::cout << colors[8] << "| " << colors[9] <<
					output_board[i][j] << colors[8] << " ";
			}
		}
		// std::cout << "\n";
		//std::cout << "---------------------------------------\n";
		if(i < 3) {
			std::cout << colors[0] << "-------------";
			std::cout << colors[1] << "-------------";
			std::cout << colors[2] << "-------------\n";
		} else if(i >=3 && i <6) {
			std::cout << colors[3] << "-------------";
			std::cout << colors[4] << "-------------";
			std::cout << colors[5] << "-------------\n";
		} else if(i >= 6 && i <= 8) {
			std::cout << colors[6] << "-------------";
			std::cout << colors[7] << "-------------";
        	std::cout << colors[8] << "-------------\n";
		}



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
	if(solved) return;
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
					if(solved) return;
					board[i][j] = 0;
					}
				}
			//* board not valid
			return;
			}
		}
    }
    // std::cout << "NICE\n";
	solved = true;
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
