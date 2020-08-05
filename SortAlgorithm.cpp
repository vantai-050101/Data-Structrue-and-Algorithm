#include "SortAlgorithm.h"
void SortAlgorithm::initArray(int low, int high) {
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
		this->elements[i] = low + rand() % (high - low + 1);
}
void SortAlgorithm::SelectionSort(char type) {
	if (type == 'i') {
		for (int i = 0; i < MAX-1; i++) {
			int min = this->elements[i], index_min = i;
			for(int j=i+1;j<MAX;j++)
				if (this->elements[j] < min) {
					min = this->elements[j];
					index_min = j;
				}
			swap(this->elements[i], this->elements[index_min]);
		}
	}
	else if (type == 'd') {
		for (int i = 0; i < MAX - 1; i++) {
			int max = this->elements[i], index_max = i;
			for (int j = i + 1; j < MAX; j++)
				if (this->elements[j] > max) {
					max = this->elements[j];
					index_max = j;
				}
			swap(this->elements[i], this->elements[index_max]);
		}
	}
}
void SortAlgorithm::InsertionSort(char type) {
	if (type == 'i') {
		for (int i = 1; i < MAX; i++) {
			int temp = this->elements[i];
			for (int j = i; 0 <= j; j--)
				if (this->elements[j - 1] > temp)
					this->elements[j] = this->elements[j - 1];
				else {
					this->elements[j] = temp;
					break;
				}
		}
	}
	else if (type == 'd') {
		for (int i = 1; i < MAX; i++) {
			int temp = this->elements[i];
			for (int j = i; 0 <= j; j--)
				if (this->elements[j - 1] < temp)
					this->elements[j] = this->elements[j - 1];
				else {
					this->elements[j] = temp;
					break;
				}
		}
	}
}
void Heapify(int arr[], int n, int i, char type) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (type == 'i') {
		if (l<n and arr[l]> arr[largest])
			largest = l;
		if (r<n and arr[r]>arr[largest])
			largest = r;
	}
	else if (type == 'd') {
		if (l<n and arr[l]< arr[largest])
			largest = l;
		if (r<n and arr[r]<arr[largest])
			largest = r;
	}
	if (largest != i) {
		swap(arr[largest], arr[i]);
		Heapify(arr, n, largest, type);
	}
}
void SortAlgorithm::HeapSort(char type) {
	for (int i = (MAX - 2) / 2; 0 <= i; i--)
		Heapify(this->elements, MAX, i, type);
	for (int i = MAX - 1; 0 < i; i--) {
		swap(this->elements[0], this->elements[i]);
		Heapify(this->elements, i, 0, type);
	}
}
int patition(int arr[],int left, int right, char type) {
	if (type == 'i') {
		int i = left;
		int j = right;
		while (i < j) {
			while (i <= j and arr[i] <= arr[left]) i++;
			while (i <= j and arr[left] <= arr[j]) j--;
			if (i < j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		swap(arr[left], arr[j]);
		return j;
	}
	else if (type == 'd') {
		int i = left;
		int j = right;
		while (i < j) {
			while (i <= j and arr[i] >= arr[left]) i++;
			while (i <= j and arr[left] >= arr[j]) j--;
			if (i < j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		swap(arr[left], arr[j]);
		return j;
	}
}
void SortAlgorithm::QuickSort(char type,int left, int right) {
	if (left < right) {
		int mid = patition(this->elements, left, right, type);
		QuickSort(type,left, mid - 1);
		QuickSort(type, mid + 1, right);
	}
}
void Merge(int arr[], int left, int mid, int right, int type) {
	int* arr_temp = new int[right - left + 1];
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid and j <= right) {
		if (arr[i] <= arr[j]) {
			arr_temp[k] = arr[i];
			i++;
		}
		else {
			arr_temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		arr_temp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= right) {
		arr_temp[k] = arr[j];
		k++;
		j++;
	}
	for (int i = left; i <= right; i++) {
		arr[i] = arr_temp[i - left];
	}
	delete arr_temp;
}
void SortAlgorithm::MergeSort(char type, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(type, left, mid);
		MergeSort(type, mid + 1, right);
		Merge(this->elements,left, mid, right, type);
	}
}
void SortAlgorithm::print()const {
	for (int i = 0; i < MAX; i++)
		cout << this->elements[i] << '\t';
	cout << '\n';
}