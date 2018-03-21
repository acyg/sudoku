#ifndef PUZZLE_H
#define PUZZLE_H

#include "Cell.h"
using namespace std;

class Puzzle {
public:
	Puzzle();
	//Puzzle(const Puzzle*);
	Puzzle(int*);
	~Puzzle();
	int basicCheck();
	int dtrPuzzle();
	bool solved();
	void print();
	Puzzle makeguess();
	void out();
	int brutSolve();
	void setCell(int, int, int);
	Cell getCell(int, int) const;
	int checkHor();
	int checkVer();
	int checkBlo();
	int checkDtr();

private:
	Cell digList[9][9];
};

#endif