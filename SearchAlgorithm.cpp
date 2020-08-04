#include "SearchAlgorithm.h"
void SearchAlgorithm::initArray(size_t n, char type) {
	this->n = n;
	long low = LOW;
	long high = HIGH;
	this->elements = new long[n];
	srand(time(NULL));
	if (type == 'n') {
		for (long i = 0; i < this->n; i++)
			this->elements[i] = low + rand() % (high - low + 1);
	}
	else if (type == 'i') {
		for (long i = 0; i < this->n; i++) {
			this->elements[i] = low + rand() % (high - low + 1);
			low = this->elements[i];
		}
	}
	else if(type == 'd'){
		for (long i = this->n - 1; 0 <= i; i--) {
			this->elements[i] = low + rand() % (high - low + 1);
			low = this->elements[i];
		}
	}
	
}
long SearchAlgorithm::getElement(size_t index)const {
	if (0 <= index and index < this->n)
		return this->elements[index];
	return -1;
}
void SearchAlgorithm::setElement(size_t index, long newValue) {
	if (0 <= index and index < this->n)
		this->elements[index] = newValue;
	else
		cout << "Error: index out of range array\n";
}
long SearchAlgorithm::LinearSearch(long value)const {
	for (int i = 0; i < this->n; i++)
		if (this->elements[i] == value)
			return i;
	return -1;
}
long SearchAlgorithm::BinarySearch(long value)const {
	int left = 0, right = this->n - 1; 
	while (left <= right) {
		int mid = (left + right) / 2;
		if (this->elements[mid] == value)
			return mid;
		else if (value < this->elements[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
long SearchAlgorithm::InterpolationSearch(long value)const {
	long left = 0, right = this->n - 1;
	while (left <= right) {
		long index = left +
			(right - left) / (this->elements[right] - this->elements[left])
			* (value - this->elements[left]);
		if (index < 0)
			break;
		else if (this->elements[index] == value)
			return index;
		else if (value < this->elements[index])
			right = index - 1;
		else
			left = index + 1;
	}
	return -1;
}
void SearchAlgorithm::printArray()const {
	for (int i = 0; i < this->n; i++)
		cout << this->elements[i] << '\t';
}