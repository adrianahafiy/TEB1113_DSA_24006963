/*
Name: Nur Adrianahafiy binti Muhammad Yazid
Student ID: 24006963
Group: G1
Question: [Easy] Efficiently compute sums of diagonals of a matrix
*/

#include <iostream>
using namespace std;

const int maxSize = 100;

void calculateDiagonalSum(int matrix[][maxSize], int n) {
	int principalD = 0;
	int secondaryD = 0;

	for (int i = 0; i < n; i++) {
		/*
		i : current row number
		n : total number of rows or columns (same as square matrix)
		*/

		principalD += matrix[i][i];
		//principal diagonal is when row = column

		secondaryD += matrix[i][n - i - 1];
		//secondary diagonal is when column = n - row - 1
	}

	cout << "Principal Diagonal Sum: " << principalD << endl;
	cout << "Secondary Diagonal Sum : " << secondaryD << endl;
}

int main() {
	//set input matrix
	int matrix[][maxSize] = { {1,5,6,7}, {5,7,3,9}, {2,6,8,1}, {4,7,3,9} };

	calculateDiagonalSum(matrix, 4);
	return 0;
}
