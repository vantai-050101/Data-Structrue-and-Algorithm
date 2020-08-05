#include "PriorityQueue.h"
bool compair(pair<int, int> a, pair<int, int>b) {
	if (a.second > b.second or
		(a.second == b.second and a.first > b.first))
		return true;
	return false;
}
void Heapify(vector<pair<int, int>>& arr, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < arr.size() and compair(arr[l],arr[largest]) == true)
		largest = l;
	if (r < arr.size() and compair(arr[r], arr[largest]) == true)
		largest = r;
	if (i != largest) {
		swap(arr[i], arr[largest]);
		Heapify(arr, largest);
	}
}
void PriorityQueue::push(pair<int, int> element) {
	this->elements.push_back(element);
	int i = abs(int(this->elements.size() - 2)) / 2;
	for (; 0 <= i; i--)
		Heapify(this->elements, i);
}
bool PriorityQueue::isEmpty()const {
	if (this->elements.empty())
		return true;
	return false;
}
void PriorityQueue::pop() {
	this->elements.erase(this->elements.begin());
	int i = abs(int(this->elements.size() - 2)) / 2;
	for (; 0 <= i; i--)
		Heapify(this->elements, i);
}
pair<int,int> PriorityQueue::front()const {
	return this->elements[0];
}
pair<int, int> PriorityQueue::get(int index)const {
	return this->elements[index];
}
void PriorityQueue::clear() {
	this->clear();
}
void PriorityQueue::print()const {
	for (int i = 0; i < this->elements.size(); i++)
		printf("Data: %d, Level: %d\n", this->elements[i].first, this->elements[i].second);
}