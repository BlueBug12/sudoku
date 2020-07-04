
#include<iostream>
#include "Solver.h"
#include "User.h"

int main(){
	int mode = 0;
	
	cout << "Welcome the world of sudoku!" << endl;
	cout << "If you want to solve sudoku, enter 1" << endl;
	cout << "If you want to play sudoku, enter 2" << endl;
	cout << "Choose mode:";
	cin >> mode;

	while (mode != 1 && mode != 2){
		cout << endl;
		cout << "False mode!" << endl;
		cout << "If you want to solve sudoku, enter 1" << endl;
		cout << "If you want to play sudoku, enter 2" << endl;
		cout << "Choose mode:";
		cin >> mode;
	}

	//choose mode
	if (mode == 1){
		//solve part
		string fileName;
		cout << "Enter the file name:";
		cin >> fileName;
		cout << endl;
		Solver solver(fileName);

		if (!solver.exhaustion()){
			cout << '0' << endl;
		}
		else{
			if (solver.mutiple()){ cout << 2 << endl; }
			else{ cout << 1 << endl; }
			solver.print();
		}
	}


	else if (mode == 2){
		//play part
		User user;
		int blank = 0;
		if (SIZE == 12){
			cout << "Enter how many blanks you want(1~70):";
			cin >> blank;
			while (blank<1 || blank>70){
				cout << endl;
				cout << "Out off range!" << endl;
				cout << "Enter how many blanks you want(1~70):";
				cin >> blank;
			}
		}
		else{
			cout << "Enter how many blanks you want(1~50):";
			cin >> blank;
			while (blank<1 || blank>50){
				cout << endl;
				cout << "Out off range!" << endl;
				cout << "Enter how many blanks you want(1~50):";
				cin >> blank;
			}
		}
		user.initial(blank);
		user.printTopic();
		cout << "If you have finished , enter 'Z'" << endl;
		cout << "If you want to recover the last step , enter 'R'" << endl;

		unsigned int t = time(NULL);
		while (user.in()){

			if (user.if_recover()){
				user.recover();
			}
			else{
				user.setAnswer();
				user.record();
			}
			cout << "-----------------------------------------" << endl;
			user.printTopic();
			cout << "If you have finished , enter 'Z'" << endl;
			cout << "If you want to recover the last step , enter 'R'" << endl;
		}
		cout << endl;
		unsigned int past_t = time(NULL) - t;
		cout << "You take " << past_t << "s to solve the sudoku!" << endl;
		if (user.correct()){ cout << "The answer is correct" << endl; }
		else{
			cout << "The answer is wrong" << endl;
			cout << "Answer:" << endl;
			user.printAnswer();
		}
	}

	return 0;
}

