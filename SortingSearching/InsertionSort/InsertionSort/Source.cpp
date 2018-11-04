#include <iostream>

using namespace std;

/*
Time Complexity : O(n^2) 
[Base Case : O(n) (almost sorted array)]
[Average Case : O(n^2)]
[Worst Case : O(n^2)]
Note : Better than Bubble sort and Selection Sort.

Space Complexity : O(1)
*/

void selectionSort(int A[], int n){
	int value, filler;
	for (int i = 1; i < n; i++)
	{
		value = A[i];
		filler = i;
		while (filler > 0 && A[filler - 1] > value) {
			A[filler] = A[filler - 1];
			filler = filler-1;
		}
		A[filler] = value;
	}
}

int main() {
	int A[] = { 2, 7, 4, 1, 5, 3 };
	int size = sizeof(A) / sizeof(A[0]);
	selectionSort(A, size);

	cout << "Insertion Sort : ";
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}

	return 0;
}