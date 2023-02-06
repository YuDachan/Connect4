#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>

using namespace std;

bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false) {
			return false;
		}

	return true;
}

int ninput(int col) {
	char x[1024];
	int y = -1;

	cout << "enter column" << endl;
	cin.getline(x, 1023);
	y = atoi(x);
	if (isNumber == false) {
		cout << "error" << endl;
		y = ninput(col) + 1;
	}
	else if (strlen(x) > 2) {
		cout << "error" << endl;
		y = ninput(col) + 1;
	}
	else if (y > col) {
		cout << "error" << endl;
		y = ninput(col) + 1;
	}
	return y - 1;
}

void init(char*** arr, int row, int col) {
	*arr = new char* [(row + 1)];
	for (int i = 0; i <= row; ++i)
		(*arr)[i] = new char[col];

	for (int i = 0; i <= row; ++i) {
		for (int j = 0; j < col; ++j) {
			(*arr)[i][j] = ' ';
		}
	}

	for (int i = 0; i < col; i++) {
		char x = '0' + i;
		char y = '0' + (i - 9);
		if (i < 9) {
			(*arr)[row][i] = x + 1;
		}
		else if (i == 19) {
			(*arr)[row][19] = '0';
		}
		else if (i >= 9) {
			(*arr)[row][i] = y;
		}

	}
}

void delete_arr(char**& arr, int row) {
	for (int i = 0; i <= row; ++i) {
		delete[] arr[i];
		arr[i] = NULL;
	}
	delete[] arr;
	arr = NULL;
}

void print(char*** arr, int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				cout << "|\033[30;47m " << (*arr)[i][j] << " ";
			else if (i % 2 == 1 && j % 2 == 1)
				cout << "|\033[30;47m " << (*arr)[i][j] << " ";
			else
				cout << "|\033[0m " << (*arr)[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}

	for (int i = 0; i < cols; i++) {
		cout << "| " << (*arr)[rows][i] << " ";
	}
	cout << endl;
	cout << endl;

}

void check1(char*** arr, int col, int row) {
	int x = 0, input = 0;
	x = row - 1;

	input = ninput(col);

	for (int i = x; i >= 0; i--) {
		if ((*arr)[i][input] == ' ') {
			(*arr)[i][input] = 'X';
			break;
		}
		else if (i <= 0) {
			cout << "error" << endl;
			check1(arr, col, row);
		}
		else if ((*arr)[i][input] != ' ') {

		}
	}
}

void check2(char*** arr, int col, int row) {
	int x = 0, input = 0;
	x = row - 1;

	input = ninput(col);

	for (int i = x; i >= 0; i--) {
		if ((*arr)[i][input] == ' ') {
			(*arr)[i][input] = 'O';
			break;
		}
		else if (i <= 0) {
			cout << "error" << endl;
			check2(arr, col, row);
		}
		else if ((*arr)[i][input] != ' ') {

		}
	}
}

int CPU(int col, int row, char*** arr) {
	int x;
	srand(time(NULL));
	x = (rand() % col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == ' ' && (*arr)[i][j + 1] == 'O' && (*arr)[i][j + 2] == 'O' && (*arr)[i][j + 3] == 'O') {
				return j;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'O' && (*arr)[i][j + 1] == ' ' && (*arr)[i][j + 2] == 'O' && (*arr)[i][j + 3] == 'O') {
				return j + 1;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'O' && (*arr)[i][j + 1] == 'O' && (*arr)[i][j + 2] == ' ' && (*arr)[i][j + 3] == 'O') {
				return j + 2;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'O' && (*arr)[i][j + 1] == 'O' && (*arr)[i][j + 2] == 'O' && (*arr)[i][j + 3] == ' ') {
				return j + 3;
			}
		}
	}
	return x;
}

void CPUI1(char*** arr, int col, int row) {
	int x = 0, y = 0;
	x = row - 1;

	y = CPU(col, row, arr);

	for (int i = x; i >= 0; i--) {
		if ((*arr)[i][y] == ' ') {
			(*arr)[i][y] = 'O';
			break;
		}
		else if (i <= 0) {
			cout << "poor input by CPU" << endl;
			cout << "press enter to continue" << endl;
			cin.ignore();
			CPUI1(arr, col, row);
		}
		else if ((*arr)[i][y] != ' ') {

		}
	}
}

void CPUI2(char*** arr, int col, int row) {
	int x = 0, y = 0;
	x = row - 1;

	y = CPU(col, row, arr);

	for (int i = x; i >= 0; i--) {
		if ((*arr)[i][y] == ' ') {
			(*arr)[i][y] = 'X';
			break;
		}
		else if (i <= 0) {
			cout << "poor input by CPU" << endl;
			cout << "press enter to continue" << endl;
			cin.ignore();
			CPUI1(arr, col, row);
		}
		else if ((*arr)[i][y] != ' ') {

		}
	}
}

bool connect1(char*** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'X' && (*arr)[i][j + 1] == 'X' && (*arr)[i][j + 2] == 'X' && (*arr)[i][j + 3] == 'X') {
				return true;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'X' && (*arr)[i + 1][j] == 'X' && (*arr)[i + 2][j] == 'X' && (*arr)[i + 3][j] == 'X') {
				return true;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'X' && (*arr)[i + 1][j + 1] == 'X' && (*arr)[i + 2][j + 2] == 'X' && (*arr)[i + 3][j + 3] == 'X') {
				return true;
			}
		}
	}


	for (int i = 3; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'X' && (*arr)[i - 1][j + 1] == 'X' && (*arr)[i - 2][j + 2] == 'X' && (*arr)[i - 3][j + 3] == 'X') {
				return true;
			}

		}
	}
	
	return false;
}

bool connect2(char*** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'O' && (*arr)[i][j + 1] == 'O' && (*arr)[i][j + 2] == 'O' && (*arr)[i][j + 3] == 'O') {
				return true;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'O' && (*arr)[i + 1][j] == 'O' && (*arr)[i + 2][j] == 'O' && (*arr)[i + 3][j] == 'O') {
				return true;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'O' && (*arr)[i + 1][j + 1] == 'O' && (*arr)[i + 2][j + 2] == 'O' && (*arr)[i + 3][j + 3] == 'O') {
				return true;
			}
		}
	}

	
	for (int i = 3; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == 'O' && (*arr)[i - 1][j + 1] == 'O' && (*arr)[i - 2][j + 2] == 'O' && (*arr)[i - 3][j + 3] == 'O') {
				return true;
			}

		}
	}
	

	return false;
}

void board(int* row, int* col) {
	char x[1024];
	int y = -1;

	do {
		cout << "enter number of columns" << endl;
		cin.getline(x, 1023);
		y = atoi(x);
		if (isNumber == false) {
			cout << "error" << endl;
			y = -1;
		}
		else if (y > 20) {
			cout << "error" << endl;
			y = -1;
		}
		else if (y < 4) {
			cout << "error" << endl;
			y = -1;
		}
	} while (y <= 0);
	*col = y;

	do {
		cout << "enter number of rows" << endl;
		cin.getline(x, 1023);
		y = atoi(x);
		if (isNumber == false) {
			cout << "error" << endl;
			y = -1;
		}
		else if (y > 20) {
			cout << "error" << endl;
			y = -1;
		}
		else if (y < 4) {
			cout << "error" << endl;
			y = -1;
		}
	} while (y <= 0);
	*row = y;

	//This could be split into two functions, but I figured that using one function to configure the board would be better
}

void twoplayer(char*** arr, int row, int col) {
	for (int i = 0; i < (row * col) /2; i++) {
		print(arr, row, col);
		cout << "player 1" << endl;
		check1(arr, col, row);
		cout << endl;
		if (connect1(arr, row, col) == true) {
			cout << "Player 1 win!" << endl;
			break;
		}
		print(arr, row, col);
		cout << "player 2" << endl;
		cout << endl;
		check2(arr, col, row);
		if (connect2(arr, row, col) == true) {
			cout << "Player 2 win!" << endl;
			break;
		}
		if (i == ((row * col) / 2) - 1) {
			cout << "Draw!" << endl;
		}
	}
	print(arr, row, col);
}

int playerselect() {
	char x[1024];
	int y = -1;

	do {
		cout << "[1]Singleplayer [2]Multiplayer" << endl;
		cin.getline(x, 1023);
		y = atoi(x);
		if (isNumber == false) {
			cout << "error" << endl;
			cout << endl;
		}
		if ((y != 1) && (y != 2)) {
			cout << "error" << endl;
			cout << endl;
		}
	} while ((y != 1) && (y != 2));

	return y;
}

int playagain() {
	char x[1024];
	int y = -1;

	do {
		cout << "Would you like to play again?" << endl;
		cout << "[1]Yes [2]No" << endl;
		cin.getline(x, 1023);
		y = atoi(x);
		if (isNumber == false) {
			cout << "error" << endl;
			cout << endl;
		}
		if ((y != 1) && (y != 2)) {
			cout << "error" << endl;
			cout << endl;
		}
	} while ((y != 1) && (y != 2));

	return y;
}

void command(int argc, char** argv, int* row, int* col, int* player) {
	if ((argc) == 4) {
		*player = atoi(argv[1]);
		*row = atoi(argv[2]);
		*col = atoi(argv[3]);

		if ((atoi(argv[1]) != 1) && (atoi(argv[1]) != 2)) {
			*player = playerselect();
		}
		if ((atoi(argv[2]) > 20) || (atoi(argv[2]) < 4)) {
			board(row, col);
		}
		else if ((atoi(argv[3]) > 20) || (atoi(argv[3]) < 4)) {
			board(row, col);
		}
	}
	else {
		*player = playerselect();
		board(row, col);
	}
}

void oneplayerp(char*** arr, int row, int col) {
	for (int i = 0; i < (row * col) / 2; i++) {
		print(arr, row, col);
		cout << "player 1" << endl;
		check1(arr, col, row);
		cout << endl;
		if (connect1(arr, row, col) == true) {
			cout << "Player 1 win!" << endl;
			break;
		}
		print(arr, row, col);
		cout << "CPU" << endl;
		cout << endl;
		CPUI1(arr, col, row);
		if (connect2(arr, row, col) == true) {
			cout << "CPU win!" << endl;
			break;
		}
		if (i == ((row * col) / 2) - 1) {
			cout << "Draw!" << endl;
		}
	}
	print(arr, row, col);


}

void oneplayerc(char*** arr, int row, int col) {
	for (int i = 0; i < (row * col) / 2; i++) {
		print(arr, row, col);
		cout << "CPU" << endl;
		CPUI2(arr, col, row);
		cout << endl;
		if (connect1(arr, row, col) == true) {
			cout << "cpu win!" << endl;
			break;
		}
		print(arr, row, col);
		cout << "player 1" << endl;
		cout << endl;
		check2(arr, col, row);
		if (connect2(arr, row, col) == true) {
			cout << "player 1 win!" << endl;
			break;
		}
		if (i == ((row * col) / 2) - 1) {
			cout << "Draw!" << endl;
		}
	}
	print(arr, row, col);


}

int move() {
	char x[1024];
	int y = -1;

	do {
		cout << "[1]First move player [2]First move CPU" << endl;
		cin.getline(x, 1023);
		y = atoi(x);
		if (isNumber == false) {
			cout << "error" << endl;
			cout << endl;
		}
		if ((y != 1) && (y != 2)) {
			cout << "error" << endl;
			cout << endl;
		}
	} while ((y != 1) && (y != 2));

	return y;
}

int main(int argc, char* argv[]) {
	char** arr = NULL;
	int n = 0, player = 0, cinput, fmove = 0;
	int row = 5, col = 5;
	cout << endl;

	command(argc, argv, &row, &col, &player);

	do {
		init(&arr, row, col);
		cinput = 0;
		if (player == 1) {
			fmove = move();
			if(fmove == 1)
				oneplayerp(&arr, row, col);
			else if (fmove == 2)
				oneplayerc(&arr, row, col);
		}
		else if (player == 2) {
			twoplayer(&arr, row, col);
		}
		cinput = playagain();
	} while (cinput != 2);

	delete_arr(arr, row);
	return 0;
}