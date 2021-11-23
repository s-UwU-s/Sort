#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void printArr(int* arr, int size);
int* initArr(int size);
void BublleSort(int* arr, int size);
void sellectionSort(int* arr, int size);
void insertSort(int* arr, int size);

int main() {
	int size = 100000;
	srand(time(NULL));
	int* arr = initArr(size);
	//printArr(arr, size);
	auto t1 = std::chrono::high_resolution_clock::now();
	//BublleSort(arr, size);
	//printArr(arr, size);
	//sellectionSort(arr, size);
	//printArr(arr, size);
	insertSort(arr, size);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << duration;
	//printArr(arr, size);
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* initArr(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50 + 1;
	}
	return arr;
}

void BublleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void sellectionSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int tmp = arr[i];
		int index = i;
		for (int j = i; j < size; j++) {
			if (tmp > arr[j]) {
				tmp = arr[j];
				index = j;
			}
		}
		swap(arr[i], arr[index]);
		//printArr(arr, size);
	}
}

void insertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int j = i + 1;
		int tmp = arr[j];
		for (; j >= 0 && tmp < arr[j - 1]; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
		//printArr(arr, size);
	}
}
