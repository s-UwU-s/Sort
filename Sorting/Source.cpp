#include <iostream>

using namespace std;

void printArr(int* arr, int size);
int* initArr(int size);
void BublleSort(int* arr, int size);

int main() {
	int size = 10;
	srand(time(NULL));
	int* arr = initArr(size);
	printArr(arr, size);
	BublleSort(arr, size);
	printArr(arr, size);
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
