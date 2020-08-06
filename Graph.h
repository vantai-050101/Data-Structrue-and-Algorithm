//#pragma once
//#include <iostream>
//#include <vector>
//#include <time.h>
//#include <queue>
//#include <stack>
//using namespace std;
//class Matrix {
//private:
//	vector <vector<int>> matrix;
//public:
//	void initMatrix(int n) {
//		srand(time(NULL));
//		for (int i = 0; i < n; i++) {
//			vector <int> temp;
//			for (int j = 0; j < n; j++)
//				if (rand() % 2 == 1 && j > i) {
//					int n = 1 + rand() % 11;
//					temp.push_back(n);
//				}
//				else
//					temp.push_back(0);
//			this->matrix.push_back(temp);
//		}
//		for (int i = 0; i < n; i++)
//			for (int j = i + 1; j < n; j++)
//				this->matrix[j][i] = this->matrix[i][j];
//	}
//	void initMatrix_zeros(int n) {
//		for (int i = 0; i < n; i++) {
//			vector <int> temp;
//			for (int j = 0; j < n; j++)
//				temp.push_back(0);
//			this->matrix.push_back(temp);
//		}
//
//	}
//	void showMatrix()const {
//		for (int i = 0; i < this->matrix.size(); i++) {
//			for (int j = 0; j < this->matrix[i].size(); j++)
//				cout << this->matrix[i][j] << '\t';
//			cout << '\n';
//		}
//	}
//	vector <vector<int>> getMatrix()const {
//		return this->matrix;
//	}
//	int getSize()const {
//		return this->matrix.size();
//	}
//	vector <pair<int, int>> BFS_edge()const {
//		// flag
//		Matrix a;
//		a.initMatrix_zeros(this->getSize());
//		vector <vector<int>> flag = a.getMatrix();
//		//list elements BFS
//		vector<pair<int, int>> list;
//		// init first Node
//		queue<pair<int, int>> q;
//		q.push({ 0,0 });
//		while (!q.empty()) {
//			pair<int, int> temp = q.front();
//			list.push_back(temp);
//			int i = temp.second;
//			for (int j = 0; j < this->getSize(); j++)
//				if (flag[i][j] == 0 and flag[i][j] == 0 and this->matrix[i][j] != 0) {
//					flag[i][j] = 1;
//					flag[j][i] = 1;
//					q.push({ i,j });
//				}
//			q.pop();
//		}
//		return list;
//	}
//	vector<int> BFS_vegre()const {
//		vector <int> flag;
//		for (int i = 0; i < this->getSize(); i++)
//			flag.push_back(0);
//		queue<int> q;
//		vector<int> list;
//		q.push(0);
//		flag[0] = 1;
//		while (!q.empty()) {
//			int i = q.front();
//			list.push_back(i);
//			for (int j = 0; j < this->getSize(); j++)
//				if (flag[j] == 0 and this->matrix[i][j] != 0) {
//					q.push(j);
//					flag[j] = 1;
//				}
//			q.pop();
//		}
//		return list;
//	}
//	
//};
