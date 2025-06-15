/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Problem: Tic-Tac-Toe Validation
*/

#include <iostream>
using namespace std;

//list win combinations (row, column, diagonal)
int winList[8][3] = { {0, 1, 2},
				{3, 4, 5},
				{6, 7, 8},
				{0, 3, 6},
				{1, 4, 7},
				{2, 5, 8},
				{0, 4, 8},
				{2, 4, 6} };

//function to check win
bool winCheck(char *board, char character) {
	for (int i = 0; i < 8; i++) {
		if (board[winList[i][0]] == character &&
			board[winList[i][1]] == character &&
			board[winList[i][2]] == character) {
			return true;
		}
		return false;
	};
}

bool validityCheck(char board[9]) {
	int xCount = 0, oCount = 0;

	//count number of Xs and Os
	for (int i = 0; i < 9; i++) {
		if (board[i] == 'X') {
			xCount++;
		}
		else if (board[i] == 'O') {
			oCount++;
		}		
	}

	//check count validity
	if (xCount == oCount || xCount == oCount + 1) {

		bool xWins = winCheck(board, 'X');
		bool oWins = winCheck(board, 'O');

		if (oWins && xWins) {
			return false;
		}
		else if (oWins && xCount != oCount) {
			return false;
		}
		else if (xWins && xCount != oCount + 1) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int main() {
	char board[] = {'O', 'X', 'X',
					'X', 'O', 'X',
					'X', 'O', 'O'};

	cout << (validityCheck(board) ? "Given board is valid" : "Given board is invalid");

	return 0;
}