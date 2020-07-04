#ifndef SOLVER_H
#define SOLVER_H
#include<iostream>
#include <array>
#include <vector>
#include <fstream>
#include <ctime>
#include "File.h"
#include "Data.h"

using namespace std;
class Solver{

public:
	Solver(vector<vector<int>>&question);

	Solver(string q_name);//friend of the class File

	void setting();

	void scan();

	void print()const;

	void find_blank();//find all 0

	bool checkAnswer();

	void find_possible(vector<int>&row, vector<int>&column, vector<int>&grid, vector<int>&element);

	bool exhaustion(int x = 0, int p = 0);

	bool mutiple();

	void recover(int r, int c, int g);

	vector<vector<int>> get_sudoku();

private:
	vector<vector<int>>sudoku;
	vector<Data>record;
	vector<vector<int>>map;
	vector<vector<int>>row;
	vector<vector<int>>column;
	vector<vector<int>>grid;
};
#endif