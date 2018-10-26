#include <iostream>

using namespace std;

int binarySearch(int A[], int n, int x) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = static_cast<int>((start + end) / 2);
		if (x == A[mid]) {
			return mid;
		}
		else if (x > A[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}


int binarySearchRecursiveUtil(int A[], int start, int end, int x) {
	if (start > end) {
		return -1;
	}
	
	int mid = static_cast<int>((start + end) / 2);
	if (x == A[mid]) {
		return mid;
	}
	else if (x < A[mid]) {
		return binarySearchRecursiveUtil(A, start, mid - 1, x);
	}
	else {
		return binarySearchRecursiveUtil(A, mid + 1, end, x);
	}
}

int binarySearchRecursive(int A[], int n, int x) {
	int start = 0, end = n - 1;
	int result = binarySearchRecursiveUtil(A, start, end, x);
	return result;
}


int main() {
	int x;
	int A[] = {2, 4, 5, 13, 14, 15, 23};
	int n = sizeof(A) / sizeof(A[0]);
	
	cout << "Enter the number: ";
	cin >> x;

	int result = binarySearch(A, n, x);
	if (result != -1) {
		cout << "Element found at index : " << result << endl;
	}
	else {
		cout << "Element not found!\n";
	}

	result = binarySearchRecursive(A, n, x);
	if (result != -1) {
		cout << "(Recursive Binary Search) Element found at index : " << result << endl;
	}
	else {
		cout << "(Recursive Binary Search) Element not found!\n";
	}

	return 0;
}
