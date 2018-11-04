#include <iostream>

using namespace std;

/*
Time Complexity : O(n^2)
Space Complexity : O(1)
*/

void selectionSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) // n-2 passes
	{
		int i_min = i; //ith poistion : elements from i till n-1 is the unsorted part of the array
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[i_min]) {
				i_min = j; // update the index of minimum element
			}
		}
		int temp = A[i];
		A[i] = A[i_min];
		A[i_min] = temp;
	}
}

int main() {
	int A[] = { 2, 7, 4, 1, 5, 3 };
	int size = sizeof(A) / sizeof(A[0]);
	selectionSort(A, size);

	cout << "Selection Sort : ";
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}

	return 0;
}