#pragma once
#include <vector>
#include <iostream>
using namespace std;
class PriorityQueue {
private:
	vector <pair<int, int>> elements;
public:
	void push(pair<int, int> element);
	void pop();
	pair<int, int> front()const;
	pair<int, int> get(int index)const;
	bool isEmpty()const;
	void clear();
	void print()const;
};

