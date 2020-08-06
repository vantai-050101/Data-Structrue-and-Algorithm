#include <iostream>
#include <string>
#define MAX 6
using namespace std;
// init and print Matrix
int matrix[MAX][MAX] = { 0 };
void printMatrix(int n = MAX, int m = MAX) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << '\n';
	}
}

// Ma di tuan
int x[] = { -2,-1,1,2,2,1,-1,-2 };
int y[] = { 1,2,2,1,-1,-2,-2,-1 };
void go(int i = 0, int j = 0, int count = 0) {
	if (count == MAX * MAX) {
		matrix[i][j] = count;
		printMatrix();
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

// Hoan vi to hop
void hoanvi(string st = "") {
	if (st.size() == MAX)
		cout << st << '\n';
	else {
		for (int i = 1; i <= MAX; i++) {
			if (st.find(to_string(i), 0) >= st.size()) {
				st = st + to_string(i);
				hoanvi(st);
				st.pop_back();
			}
		}
	}
}

// Tam quan hau
#define N 6
#define M 6
bool try_go(int count, int i) {
	for (int j = 1; j<=count; j++)
		if (matrix[count-j][i] != 0 or
			(0 <= count - j and 0 <= i - j and matrix[count - j][i - j] != 0) or
			(0 <= count - j and i + j < M and matrix[count - j][i + j] != 0))
			return false;
	return true;
}
void tamQuanhau(int count = 0) {
	if (count == N) {
		printMatrix(N, M);
		cout << '\n';
	}
	else {
		for (int i = 0; i < M; i++)
			if (try_go(count, i) == true) {
				matrix[count][i] = 1;
				tamQuanhau(count + 1);
				matrix[count][i] = 0;
			}
	}
}

// Qua trung
bool try_(int count, int k) {
	int c = 0;
	for (int i = 0; i < count; i++) {
		if (matrix[i][k] != 0)
			c++;
		if (c > 1)
			return false;
	}
	return true;
}
void quatrung(int count = 0) {
	if (count == N) {
		printMatrix(N, M);
		cout << '\n';
	}
	else {
		for (int i = 0; i < M - 1; i++) {
			for (int j = i + 1; j < M; j++)
				if (try_(count, i) and try_(count, j)) {
					matrix[count][i] = 1;
					matrix[count][j] = 1;
					quatrung(count + 1);
					matrix[count][i] = 0;
					matrix[count][j] = 0;
				}
		}
	}
}

int main() {
	cout << "\nHoan vi to hop: ";
	hoanvi();
	cout << "\nMa di tuan: ";
	go();
	cout << "\nTam quan hau: ";
	tamQuanhau();
	cout << "\nQua trung: ";
	quatrung();
	return 0;
}