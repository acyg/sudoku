#include "Cell.h"
#include <iostream>
using namespace std;

Cell::Cell(){
	data = 0;
	pos[0] = -1;
};

Cell::Cell(int input){
	data = input;
	if(data != 0){
		pos[0] = -1;
	} else {
		for(int i = 0;i < 9;i++) {
			pos[i] = (i+1);
		}
	}
};

Cell::~Cell(){
};

void Cell::set(int input){
	data = input;
	return;
}

int Cell::get()const{
	return data;
};

const int* Cell::getPos() const{
	return pos;	
};

void Cell::print() {
	cout << "dig in cell :" << data << endl;
	if(pos[0] > -1){
		cout << "posible digs :";
		for(int i = 0;i < 9;i++) {
			cout << pos[i];
		}
		cout << endl;
	}
};

int Cell::deList(int tar){
	for(int i = 0;i < 9;i++){
		if(pos[i] == tar) {
			pos[i] = 0;
			return 1;
		}
	}
	return 0;
};

int Cell::getfirstPos(){
	int j, i;
	j = 0;
	while(pos[j] == 0){
		j++;
	}
	i = pos[j];
	pos[j] = 0;
	return i;
}
