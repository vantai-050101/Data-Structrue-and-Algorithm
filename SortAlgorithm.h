#pragma once
#define MAX 10
#include <iostream>
#include <time.h>
using namespace std;
class SortAlgorithm {
private:
	int elements[MAX];
public:
	SortAlgorithm() {};
	SortAlgorithm(const SortAlgorithm &a) {
		for (long i = 0; i < MAX; i++)
			this->elements[i] = a.elements[i];
	}
	SortAlgorithm(int arr[]) {
		for (int i = 0; i < MAX; i++)
			this->elements[i] = arr[i];
	}
	~SortAlgorithm() {};
	void initArray(int low, int high);
	void SelectionSort(char type = 'i');
	void InsertionSort(char type = 'i');
	void QuickSort(char type = 'i', int left = 0, int right = MAX - 1);
	void HeapSort(char type = 'i');
	void MergeSort(char type = 'i', int left = 0, int right = MAX - 1);
	void print()const;
};
