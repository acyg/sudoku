#include "Puzzle.h"
#include <iostream>
using namespace std;

Puzzle::Puzzle(){
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			digList[i][j] = Cell();
		}
	}
}

Puzzle::Puzzle(int* arry){
	int k = 0;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			digList[i][j] = Cell(arry[k]);
			k++;
		}
	}
}

Puzzle::~Puzzle(){
}

void Puzzle::setCell(int i, int j, int src){
	digList[i][j] = Cell(src);
}

Cell Puzzle::getCell(int i, int j) const{
	return (digList[i][j]);
}

void Puzzle::print(){
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			digList[i][j].print();
		}
		cout << endl;
	}

	return;
}

void Puzzle::out(){
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cout << (char)(digList[i][j].get() + 48);
		}
	}
	cout << endl;
}

bool Puzzle::solved(){
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(digList[i][j].get() == 0)return false;
		}
	}
	return true;
}

int Puzzle::basicCheck(){
	int result = (*this).dtrPuzzle();
	while(result > 0){
		result = (*this).dtrPuzzle();
	}
	return result;
}

int Puzzle::brutSolve(){
	int index;
	do{			
		index = (*this).basicCheck();
		if(index != -1) index = (*this).checkDtr();
		
	}while(index > 0);
	return index;
}

int Puzzle::dtrPuzzle(){
	int result;
	result = ((*this).checkHor());
	if(result < 0) return result;
	else{
		result = ((*this).checkVer());
		if(result < 0) return result;
		else{
			result = ((*this).checkBlo()); 
		}
	}
	return result;
}

Puzzle Puzzle::makeguess(){
	int k;
	Puzzle puzzleNew;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(digList[i][j].get() == 0){
				k = digList[i][j].getfirstPos();
				puzzleNew = (*this);
				(*this).setCell(i,j,k);
				i = j = 99;
			}
		}
	}

	return puzzleNew;
}

int Puzzle::checkVer(){
	int result, i, j, tar;
	result = 0;
	bool hit;
	for(j = 0; j < 9; j++) {
		tar = 1;
		while(tar < 10){
			hit = false;
			for(i = 0; i < 9; i++) {
				if(digList[i][j].get() == tar){
					if(hit != true){
						hit = true;
					} else {
						i = j = tar = 99;
						hit = false;
						result = -1;
					}
				}
			}
			if(hit){
				for(i = 0; i < 9; i++) {
					if(digList[i][j].get() == 0) result = digList[i][j].deList(tar);
				}
			}
			tar++;
		}
	}

	return result;
}

int Puzzle::checkHor(){
	int result, i, j, tar;
	result = 0;
	bool hit;
	for(i = 0; i < 9; i++) {
		tar = 1;
		while(tar < 10){
			hit = false;
			for(j = 0; j < 9; j++) {
				if(digList[i][j].get() == tar){
					if(hit != true){
						hit = true;
					} else {
						i = j = tar = 99;
						hit = false;
						result = -1;
					}
				}
			}
			if(hit){
				for(int j = 0; j < 9; j++) {
					if(digList[i][j].get() == 0) result = digList[i][j].deList(tar);
				}
			}
			tar++;
		}
	}

	return result;
}

int Puzzle::checkBlo(){
	int result, tar, x, y, i, j;
	result = 0;
	bool hit;
	for(x = 3;x < 10;x += 3){
		for(y = 3;y < 10;y += 3){
			tar = 1;
			while(tar < 10){
				hit = false;
				for(i = x - 3;i < x;i++){
					for(j = y - 3;j < y;j++){
						if(digList[i][j].get() == tar){
							if(hit != true){
								hit = true;
							} else {
								i = j = x = y = tar = 99;
								hit = false;
								result = -1;
							}
						}
					}

				}
				if(hit){
					for(i = x - 3;i < x;i++) {
						for(j = y - 3;j < y;j++) {
							if(digList[i][j].get() == 0) result = digList[i][j].deList(tar);
						}
					}
				}
				tar++;
			}
		}
	}

	return result;
}

int Puzzle::checkDtr(){
	int result, i, j, k, dtr;
	result = 0;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			if(digList[i][j].get() == 0){
				k = 0;
				dtr = -1;
				while(k < 9){
					if((digList[i][j].getPos())[k] != 0) {
						if(dtr > 0){
							dtr = 0;
							k = 99;
						}else dtr = (digList[i][j].getPos())[k];
					}
					k++;
				}
				if(dtr < 0) result = -1;
				else if(dtr > 0) {
					digList[i][j] = Cell(dtr);
					result = 1;
				} 
			}
		}
	}

	return result;
}
