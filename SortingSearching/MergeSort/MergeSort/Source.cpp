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

void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
	//i - to mark the index of left subarray (L)
	//j - to mark the index of right subarray (R)
	//k - to mark the index of merged subarray (A)
	int i, j, k;
	i = j = k = 0;
	while (i < leftCount && j < rightCount) {
		if (L[i] < R[j]) {
			A[k++] = L[i++];
		}
		else {
			A[k++] = R[j++];
		}
	}
	while (i < leftCount) {
		A[k++] = L[i++];
	}
	while (j < rightCount) {
		A[k++] = R[j++];
	}
}

void mergeSort(int* A, int n) {
	int mid, i, *L, *R;
	
	//base condition - if the array has less than two elements, do nothing
	if (n < 2) {
		return;
	}

	mid = static_cast<int>(n/2);
	L = new int(mid);
	R = new int(n - mid);
	//creating left subarray
	for (i = 0; i < mid; i++) {
		L[i] = A[i];
	}
	//creating right subarray
	for (i = mid; i < n; i++) {
		R[i-mid] = A[i];
	}
	//mergin L and R into A as sorted list
	merge(A, L, mid, R, n - mid);
}

int main() {
	int A[] = { 2, 4, 1, 6, 8, 5, 3, 7};
	int size = sizeof(A) / sizeof(A[0]);
	mergeSort(A, size);

	cout << "Merge Sort : ";
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}

	return 0;
}