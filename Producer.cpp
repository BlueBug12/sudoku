#include "Producer.h"

	Producer::Producer(vector<vector<int>>& result){

		//fill the sudoku with 0

		for (int i = 0; i < SIZE; ++i){ initilizer.push_back(0); }
		result.assign(SIZE, initilizer);

		if (SIZE == 12){
			for (int i = 0; i < 4; ++i){ black_space[i] = i; }


			//random the black space
			rand_black();

			//fill the black space with -1
			for (int i = 0; i < 4; ++i){
				for (int j = 0; j < 3; ++j){
					for (int k = 0; k < 3; ++k){
						result[i * 3 + j][black_space[i] * 3 + k] = -1;
					}
				}
			}
		}
	}

	void Producer::rand_black(){
		srand(time(NULL));
		int temp1 = 0;
		int temp2 = 0;
		for (int i = 0; i < 10; ++i){
			int a = rand() % 4;
			int b = rand() % 4;
			temp1 = black_space[a];
			temp2 = black_space[b];
			black_space[a] = temp2;
			black_space[b] = temp1;
		}
	}

	void Producer::full_template(vector<vector<int>>& result){
		Solver solver(result);
		if (solver.exhaustion() == 0){ cout << "fail" << endl; }
		result = solver.get_sudoku();
	}

	vector<vector<int>> Producer::produce(vector<vector<int>>& result, int blank){

		for (int i = 0; i < SIZE; ++i){
			for (int j = 0; j < SIZE; ++j){
				if (result[i][j] != -1){
					Data mark;
					mark.row_y = i;
					mark.column_x = j;
					position.push_back(mark);
				}
			}
		}

		vector<vector<int>>temp = result;

		hollow(temp, blank);
		vector<vector<int>>copy = temp;

		Solver s(temp);
		s.exhaustion();

		while (s.mutiple()){
			//recover the template
			temp = result;
			hollow(temp, blank);
			copy = temp;
			Solver s(temp);
		}

		return copy;
	}

	void Producer::hollow(vector<vector<int>>&temp, int number){
		if (number > 108){ cout << "Out of the boundry" << endl; }
		else{
			vector<Data>copy_p = position;

			srand(time(NULL));
			int seed = 0;
			for (int i = 0; i < number; ++i){
				seed = rand() % copy_p.size();
				temp[copy_p.at(seed).row_y][copy_p.at(seed).column_x] = 0;
				copy_p.erase(copy_p.begin() + seed);
			}
		}
	}

	void Producer::print(vector<vector<int>>& result)const{
		for (int i = 0; i<SIZE; ++i){
			for (int j = 0; j<SIZE; ++j){
				if (result[i][j] == -1){ cout << 'X' << " "; }
				else{ cout << result[i][j] << " "; }
			}
			cout << endl;
		}
	}


