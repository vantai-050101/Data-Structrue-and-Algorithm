#include "HashTable.h"
size_t HashTable::Hash(int Vaule)const {
	return abs(Vaule % this->N);
}
void HashTable::init(int n) {
	this->N = n;
	vector <int> emptyBucket;
	for (int i = 0; i < n; i++)
		this->buckets.push_back(emptyBucket);
}
void HashTable::autoInput(int n,int low,int high) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		this->add(low + rand() % (high - low + 1));
}
void HashTable::print()const {
	for (int i = 0; i < this->buckets.size(); i++) {
		printf("Bucket[%d]: ", i);
		for (int j = 0; j < this->buckets[i].size(); j++)
			cout << '\t' << this->buckets[i][j];
		cout << '\n';
	}
}
int HashTable::getNumberOfBuckets()const {
	return this->N;
}
vector<vector<int>> HashTable::getBuckets()const {
	return this->buckets;
}
bool HashTable::isEmpty()const {
	for (int i = 0; i < this->N; i++)
		if (!this->buckets[i].empty())
			return false;
	return true;
}
void HashTable::add(int newValue) {
	size_t index = this->Hash(newValue);
	this->buckets[index].push_back(newValue);
}
void HashTable::del(int Value) {
	size_t index = this->Hash(Value);
	for (int i = 0; i < this->buckets[index].size(); i++)
		if (this->buckets[index][i] == Value) {
			this->buckets[index].erase(this->buckets[index].begin() + i);
			i--;
		}
}
vector<pair<int,int>> HashTable::find(int Value)const {
	size_t index = this->Hash(Value);
	vector<pair<int, int>> l;
	pair<int, int> temp;
	for (size_t i = 0; i < this->buckets[index].size(); i++) {
		if (this->buckets[index][i] == Value) {
			temp = { index,i };
			l.push_back(temp);
		}
	}
	return l;
}
void HashTable::update(int Value, int newValue) {
	this->del(Value);
	this->add(newValue);
}
