#ifndef PRODUCER_H
#define PRODUCER_H
#include<iostream>
#include<array>
#include<vector>
#include <ctime>
#include "Solver.h"

using namespace std;
class Producer{

public:
	Producer(vector<vector<int>>& result);

	void rand_black();

	void full_template(vector<vector<int>>& result);

	vector<vector<int>> produce(vector<vector<int>>& result, int blank);

	void hollow(vector<vector<int>>&temp, int number);

	void print(vector<vector<int>>& result)const;

private:
	int black_space[4];
	vector<int>initilizer;
	vector<vector<int>>row;
	vector<vector<int>>column;
	vector<vector<int>>grid;
	vector<Data>position;
};
#endif
