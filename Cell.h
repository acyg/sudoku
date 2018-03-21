#ifndef CELL_H
#define CELL_H

using namespace std;

class Cell {
public:
	Cell();
	Cell(int);
	~Cell();
	void set(int);
	int getfirstPos();
	int get()const;
	const int* getPos() const;
	int deList(int);
	void print();

private:
	int data;
	int pos[9];
};

#endif