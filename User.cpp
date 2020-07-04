#include "User.h"

	User::User(){
		row = 0;
		column = 0;
		number = 0;
		re = 0;
	}

	void User::initial(int number){
		vector<vector<int>>s1;
		Producer producer(s1);
		producer.full_template(s1);
		answer = s1;
		topic = producer.produce(s1, number);
	}

	void User::printTopic(){
		cout << "  ";
		for (int i = 0; i < SIZE; ++i){
			char x = 65 + i;
			cout << x << " ";
		}
		cout << endl;
		for (int i = 0; i<SIZE; ++i){
			char y = 97 + i;
			cout << y << " ";
			for (int j = 0; j<SIZE; ++j){
				if (topic[i][j] == -1){ cout << 'X' << " "; }
				else{ cout << topic[i][j] << " "; }
			}
			cout << endl;
		}
	}

	void User::printAnswer(){
		cout << "  ";
		for (int i = 0; i < SIZE; ++i){
			char x = 65 + i;
			cout << x << " ";
		}
		cout << endl;
		for (int i = 0; i<SIZE; ++i){
			char y = 97 + i;
			cout << y << " ";
			for (int j = 0; j<SIZE; ++j){
				if (answer[i][j] == -1){ cout << 'X' << " "; }
				else{ cout << answer[i][j] << " "; }
			}
			cout << endl;
		}
	}

	bool User::in(){
		char x = 0;
		char y = 0;
		cout << "row:";
		cin >> x;

		if (x == 'Z'){ return 0; }//end input
		if (x == 'R'){
			re = 1;
			return 1;
		}

		cout << "column:";
		cin >> y;

		row = x - 'a';
		column = y - 'A';

		while (1){
			if (row < 0 || row >= SIZE || column < 0 || column >= SIZE){
				cout << "Wrong position!" << endl;
			}
			else if (topic[row][column] != 0){
				cout << "The position isn't 0!" << endl;
			}
			else{
				break;
			}
			cout << "row:";
			cin >> x;
			if (x == 'Z'){ return 0; }//end input
			if (x == 'R'){
				re = 1;
				return 1;
			}
			cout << "column:";
			cin >> y;

			row = x - 'a';
			column = y - 'A';
		}

		cout << "Enter the number:";
		cin >> number;
		while (number<1 || number>9){
			cout << "Enter the number:";
		}
		return 1;
	}

	void User::setAnswer(){
		topic[row][column] = number;
	}

	void User::record(){
		Data one;
		one.row_y = row;
		one.column_x = column;
		recorder.push_back(one);
	}

	bool User::if_recover(){
		if (re == 1){ return 1; }
		else{ return 0; }
	}

	void User::recover(){
		if (recorder.size() > 0){
			int position = recorder.size() - 1;
			topic[recorder.at(position).row_y][recorder.at(position).column_x] = 0;
			recorder.erase(recorder.begin() + position);
		}
		re = 0;
	}

	bool User::correct(){
		if (topic == answer){
			return 1;
		}
		else{ return 0; }
	}

