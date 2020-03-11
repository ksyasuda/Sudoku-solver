Sudoku solver with a variable sized board

Uses backtracking to find the solution to the board

To run the program first run make with the included makefile to build
Then run ./solver [boardsize] [filename] with a valid sudoku board as input

The program prints to stdout and can be redirected to an output file by running
	./solver [boardsize] [filename] > [outputfile]

To create a input file create a text file with space separated integers ranging
from 1-9 for the initial values and 0 for all unknown values

The input can be formatted in any way as long as the integers are space separated
