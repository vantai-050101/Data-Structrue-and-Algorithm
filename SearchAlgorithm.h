#pragma once
#include <iostream>
#include <time.h>
#define LOW -50
#define HIGH 30
using namespace std;
class SearchAlgorithm {
private:
	size_t n;
	long* elements;
public:
	SearchAlgorithm() {};
	~SearchAlgorithm() {
		if (this->elements != NULL)
			delete this->elements;
	}
	void initArray(size_t n,char);
	void printArray()const;
	long getElement(size_t index) const;
	void setElement(size_t index, long newValue);
	long LinearSearch(long)const;
	long BinarySearch(long)const;
	long InterpolationSearch(long)const;
};

