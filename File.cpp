#include "File.h"

	File::File(string file) :filename(file){
		vector<int>initial;
		for (int i = 0; i < SIZE; ++i){ initial.push_back(0); }
		sudoku.assign(SIZE, initial);
	}

	void File::setFileIn(){
		inFile.open(filename, ios::in);
		if (!inFile){
			cerr << "Failed opening input file" << endl;
			exit(1);
		}
	}

	void File::setFileOut(string file){
		outFile.open(file, ios::out);
		if (!outFile){
			cerr << "Failed opening output file" << endl;
			exit(1);
		}
	}

	void File::readInput(vector<vector<int>> &row, vector<vector<int>> &column,
		vector<vector<int>>&grid){
		for (int i = 0; i<SIZE; ++i){
			for (int j = 0; j<SIZE; ++j){
				inFile >> text;
				if (text == ','){ --j; }
				else{
					int x = text - 48;
					if (x == -3){
						sudoku[i][j] = -1;
						inFile >> text;
					}

					else{
						sudoku[i][j] = x;
						++row[i][x];
						++column[j][x];
						++grid[(i / 3) * (SIZE / 3) + j / 3][x];
					}

				}
			}
		}
	}

	vector<vector<int>>  File::getSudoku(){
		vector<vector<int>>temp = sudoku;
		return temp;
	}


