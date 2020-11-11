# Sudoku Solver (C++)

Command-line solver for the Sudoku game

This program uses backtracking to find the solution to the board

## Installation

To install the program, make sure you have `make` and `gcc` installed then run
```bash
git clone https://github.com/ksyasuda/Sudoku-solver.git
cd sudoku-solver
make solver
```

## Usage

To run the program, use the command `./solver [boardsize] [filename]` with a valid sudoku board as input

The program prints to stdout and can be redirected to an output file `./solver [boardsize] [filename] > [outputfile]`	

To create a input file create a text file with space separated integers ranging
from 1-9 for the initial values and 0 for all unknown values

The input can be formatted in any way as long as the integers are space separated

I have included 5 example boards with two different formats that both work

## Debug

The program also has a debug executable.  To build the debug executable run

```bash
make debug
```
To use the debug executable run: `./solver_debug [bordsize] [filename]` 

This will print out the status of the board after each move instead of after a
successful or uncessful solve
