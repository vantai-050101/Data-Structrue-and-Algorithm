#include <iostream>
#define MAX 8
using namespace std;
int x[] = { -2,-1,1,2,2,1,-1,-2 };
int y[] = { 1,2,2,1,-1,-2,-2,-1 };
int matrix[MAX][MAX] = { 0 };

void printMatrix() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matrix[i][j] << '\t';
		cout << '\n';
	}
}

void go(int i, int j, int count) {
	if (count == MAX * MAX) {
		matrix[i][j] = count;
		printMatrix();

		char c;
		cout << "Do you want to print next (8 quan hau) macth Matrix: y/n? ";
		cin >> c;
		if (c == 'y');
		else if ('n')
			exit(0);
		cout << '\n';
	}
	else {
		for (int k = 0; k < 8; k++) {
			matrix[i][j] = count;
			int _x = i + x[k];
			int _y = j + y[k];
			if (0 <= _x and _x < MAX and 0 <= _y
				and _y < MAX and matrix[_x][_y] == 0) {
				go(_x, _y, count + 1);
				matrix[_x][_y] = 0;
			}
		}
	}
}

int main() {
	int i, j;
	cout << "Started point (x,y)\n";
	cout << '\t' << "x: "; cin >> i;
	cout << '\t' << "y: "; cin >> j;

	go(i, j, 1);
	
	return 0;
}