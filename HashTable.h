#pragma once
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
class HashTable {
private:
	int N;
	vector<vector<int>> buckets;
public:
	HashTable() { this->N = 0; };
	void init(int num_Buckets);
	void autoInput(int num_Elements, int low, int high);
	void print()const;
	void add(int newValue);
	void del(int Value);
	void update(int Value, int newValue);
	vector<pair<int, int>> find(int Value)const;
	size_t Hash(int)const;
	bool isEmpty()const;
	int getNumberOfBuckets()const;
	vector <vector<int>> getBuckets()const;
};
