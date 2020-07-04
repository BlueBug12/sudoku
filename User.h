#include<iostream>
#include<vector>
#include <iostream>
#include "Producer.h"
using namespace std;
class User{
public:
	User();
	void initial(int number);
	void printTopic();
	void printAnswer();
	bool in();
	void setAnswer();
	void record();
	bool if_recover();
	void recover();
	bool correct();

private:
	vector<vector<int>>topic;
	vector<vector<int>>answer;
	vector<Data>recorder;
	int row;
	int column;
	int number;
	bool re;
};
