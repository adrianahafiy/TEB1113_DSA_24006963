/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Problem: Rotate matrix 90 degree counterclockwise
*/

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>> matrix) {
	for (const auto& row : matrix) {
		for (int value : row) {
			cout << value << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> rotateMatrix(const vector<vector<int>>& inputMatrix, int ogRowSize, int ogColumnSize){

	//create new vector 2d array result matrix size column x row
	vector<vector<int>> resultMatrix(ogColumnSize, vector<int>(ogRowSize));

	for (int newRow = 0; newRow < ogRowSize; newRow++) {
		for (int newColumn = 0; newColumn < ogColumnSize; newColumn++) {
			//result matrix row has new calculation and column exchange with row number
			resultMatrix[ogColumnSize - newColumn - 1][newRow] = inputMatrix[newRow][newColumn];
		}
	}

	return resultMatrix;
}

int main() {
	int ogRowSize, ogColumnSize;

	//request for user matrix size input
	cout << "Insert original matrix row size: ";
	cin >> ogRowSize;
	cout << "Insert original matrix column size: ";
	cin >> ogColumnSize;

	//create new vector 2d array input matrix size row x column
	vector<vector<int>> inputMatrix(ogRowSize, vector<int>(ogColumnSize));

	//ask for user input
	for (int i = 0; i < ogRowSize; i++) {
		for (int j = 0; j < ogColumnSize; j++) {
			cout << "Input element [" << i << "][" << j << "]: ";
			cin >> inputMatrix[i][j];
		}
	}

	//Print original matrix
	cout << "\nOriginal Matrix:\n";
	printMatrix(inputMatrix);

	//Print rotated matrix
	vector<vector<int>> rotatedMatrix = rotateMatrix(inputMatrix, ogRowSize, ogColumnSize);
	cout << "\n\nRotated Matrix (90 degrees counterclockwise):\n";
	printMatrix(rotatedMatrix);

	return 0;
}
