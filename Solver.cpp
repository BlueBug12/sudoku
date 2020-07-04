#include "Solver.h"

	Solver::Solver(vector<vector<int>>&question) :sudoku(question){

		setting();
		scan();
		find_blank();

	}

	Solver::Solver(string q_name){
		setting();
		File file(q_name);
		file.setFileIn();

		file.readInput(row, column, grid);
		if (checkAnswer()){ cout << "The sudoku can't be solved" << endl; }
		else{
			sudoku = file.getSudoku();
			find_blank();
		}
	}

	void Solver::setting(){
		vector<int>set(10, 0);
		row.assign(SIZE, set);
		column.assign(SIZE, set);
		grid.assign(SIZE*SIZE / 9, set);
	}

	void Solver::scan(){
		for (int i = 0; i < SIZE; i++){
			for (int j = 0; j < SIZE; ++j){
				if (sudoku[i][j] != -1){
					++row.at(i).at(sudoku[i][j]);
					++column.at(j).at(sudoku[i][j]);
					++grid.at((i / 3) * (SIZE / 3) + j / 3).at(sudoku[i][j]);
				}

			}
		}
	}
	void Solver::print()const{

		for (int i = 0; i<SIZE; ++i){
			for (int j = 0; j<SIZE; ++j){
				if (sudoku[i][j] == -1){ cout << 'X' << " "; }
				else{ cout << sudoku[i][j] << " "; }
			}
			cout << endl;
		}
	}

	//find all 0
	void Solver::find_blank(){
		for (int i = 0; i < SIZE; ++i){
			for (int j = 0; j < SIZE; ++j){
				if (sudoku[i][j] == 0){
					Data mark;
					mark.row_y = i;
					mark.column_x = j;
					record.push_back(mark);
				}
			}
		}
	}

	bool Solver::checkAnswer(){
		for (int i = 0; i < row.size(); ++i){
			for (int j = 1; j < 10; ++j){
				if (row.at(i).at(j) == 2){
					return 1;
				}
			}
		}
		return 0;
	}
	void Solver::find_possible(vector<int>&row, vector<int>&column, vector<int>&grid, vector<int>&element){
		for (int i = 1; i < 10; ++i){
			if (row.at(i) == 0 && column.at(i) == 0 && grid.at(i) == 0){ element.push_back(i); }
		}
	}

	bool Solver::exhaustion(int x , int p ){
		if (checkAnswer()){ return 0; }
		int a = x;
		srand(time(NULL));

		for (; a < record.size(); ++a){
			int r = record.at(a).row_y;
			int c = record.at(a).column_x;
			int g = (record.at(a).row_y / 3) * (SIZE / 3) + (record.at(a).column_x / 3);
			vector<int>temp;

			//find all the possibility at that position
			find_possible(row.at(r), column.at(c), grid.at(g), temp);

			if (p == 1 && a == x){
				for (int d = 0; d < temp.size(); ++d){
					if (temp.at(d) == sudoku[r][c]){
						temp.erase(temp.begin() + d);
						break;
					}
				}
			}

			map.push_back(temp);
			while (temp.size() == 0){
				map.erase(map.begin() + map.size() - 1);
				--a;
				//boundary checking
				if (a == -1){
					return 0;
				}
				r = record.at(a).row_y;
				c = record.at(a).column_x;
				g = (record.at(a).row_y / 3) * (SIZE / 3) + (record.at(a).column_x / 3);
				recover(r, c, g);
				temp = map.at(map.size() - 1);

			}

			int n_postition = rand() % temp.size();
			int number = temp.at(n_postition);
			sudoku[r][c] = number;

			++row.at(r).at(number);
			++column.at(c).at(number);
			++grid.at(g).at(number);
			map.at(map.size() - 1).erase(map.at(map.size() - 1).begin() + n_postition);//erase the possibility that had been tried 
		}

		return 1;
	}

	bool Solver::mutiple(){

		int mark = 0;
		for (int i = map.size() - 1; i >-1; --i){
			if (i < 0){ return 0; }
			recover(record.at(i).row_y, record.at(i).column_x,
				(record.at(i).row_y / 3) * (SIZE / 3) + (record.at(i).column_x / 3));

			if (map.at(i).size() == 0){
				map.erase(map.begin() + i);
			}

			else{
				mark = i;
				map.erase(map.begin() + i);
				//cout << mark << endl;
				break;
			}
		}
		if (exhaustion(mark, 1)){ return 1; }//mutiple solution
		else{ return 0; }//only one solution
	}

	void Solver::recover(int r, int c, int g){
		int wrong_number = sudoku[r][c];
		--row.at(r).at(wrong_number);
		--column.at(c).at(wrong_number);
		--grid.at(g).at(wrong_number);
	}
	vector<vector<int>> Solver::get_sudoku(){
		return sudoku;
	}

