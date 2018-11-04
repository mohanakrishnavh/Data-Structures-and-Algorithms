#include <iostream>

using namespace std;

/*
Time Complexity : O(n^2)
[Base Case : O(n) (when no need to swap)]
[Average Case : O(n^2)]
[Worst Case : O(n^2)]

Space Complexity : O(1)
*/

void bubbleSort(int A[], int n) {
	for (int k = 0; k < n - 1; k++)
	{
		bool flag = false;
		for (int i = 0; i < (n - k - 1); i++) {
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]);
				flag = true;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

int main() {
	int A[] = { 2, 7, 4, 1, 5, 3 };
	int size = sizeof(A) / sizeof(A[0]);
	bubbleSort(A, size);

	cout << "Bubble Sort : ";
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}

	return 0;
}