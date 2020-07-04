#include<iostream>
#include<array>
#include<vector>
#include <fstream>
#define SIZE 12

using namespace std;

class File{
public:
	File(string file);

	void setFileIn();

	void setFileOut(string file);

	void readInput(vector<vector<int>> &row, vector<vector<int>> &column,
		vector<vector<int>>&grid);

	vector<vector<int>> getSudoku();

private:
	string filename;
	ifstream inFile;
	ofstream outFile;
	vector<vector<int>>sudoku;
	char text;
};