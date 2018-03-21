#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
#include "Puzzle.h"

using namespace std;

bool put(char, int*, int);

int main () {
	char input;
	bool coin;
	int index = 0;
	int* dig = new int[81];
	stack<Puzzle> alternatives;
	stack<Puzzle> solutions;

	do{
		input = getchar();
		coin = put(input, dig, index);
		index++;
	}while (!feof(stdin) && coin != false);

	if(coin){
		Puzzle puzzle = Puzzle(dig);

		do{
			coin = false;
			index = puzzle.brutSolve();
			//puzzle.print();
			if(index < 0){
				if(!alternatives.empty()){
					puzzle = Puzzle(alternatives.top());
					alternatives.pop();
					coin = true;
				}
			}else{
				if(puzzle.solved()){
					solutions.push(puzzle);
					if(!alternatives.empty()){
						puzzle = Puzzle(alternatives.top());
						alternatives.pop();
						coin = true;
					}
				} else alternatives.push(puzzle.makeguess());
			}

		}while(!alternatives.empty() || coin);

		if(solutions.empty())cout << "No solution.\n";
		else{
			do{
				solutions.top().out();
				solutions.pop();
			}while(!solutions.empty());
		}
	}

	return 0;
}

bool put(char input, int* dig, int index){
	bool pos = true;
	if(index < 82){
		if(index == 81) {
			if(input != '\n'){
				if(feof(stdin)) cout << "ERROR: expected \\n found <eof>\n";
				else if(isprint(input)) cout << "ERROR: expected \\n found " << input << '\n';
				else printf ("ERROR: expected \\n found \\x%02x\n", input);
				pos = false;
			} 
		}else {
			string expected = ".123456789";
			if(expected.find(input) == string::npos){
				if(feof(stdin)) cout << "ERROR: expected <value> found <eof>\n";
				else if(input == '\n') cout << "ERROR: expected <value> found \\n\n";
				else if(isprint(input)) cout << "ERROR: expected <value> found " << input << '\n';
				else printf ("ERROR: expected <value> found \\x%02x\n", input);
				pos = false;
			}
			else if(input == '.')dig[index] = 0;
			else dig[index] = ((int)input) - 48;
		}
	}
	else {
		if(!feof(stdin)){
			if(input == '\n') cout << "ERROR: expected <eof> found \\n\n";
			else if(isprint(input)) cout << "ERROR: expected <eof> found " << input << '\n';
			else printf ("ERROR: expected <eof> found \\x%02x\n", input);
			pos = false;
		}
	}
	return pos;
};

