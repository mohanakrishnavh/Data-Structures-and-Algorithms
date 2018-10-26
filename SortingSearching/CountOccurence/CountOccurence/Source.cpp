#include <iostream>

using namespace std;

int findMinimumIndex(int A[], int n, int x) {
	int start = 0, end = n - 1, min_index = -1;
	while (start <= end) {
		int mid = static_cast<int>((start + end) / 2);
		if (x == A[mid]) {
			min_index = mid;
			end = mid - 1;
		}
		else if (x > A[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return min_index;
}

int findMaximumIndex(int A[], int n, int x) {
	int start = 0, end = n - 1, max_index = -1;
	while (start <= end) {
		int mid = static_cast<int>((start + end) / 2);
		if (x == A[mid]) {
			max_index = mid;
			start = mid + 1;
		}
		else if (x > A[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return max_index;
}

int findMinMaxIndex(int A[], int n, int x, bool minimum) {
	int start = 0, end = n - 1, result = -1;
	while (start <= end) {
		int mid = static_cast<int>((start + end) / 2);
		if (x == A[mid]) {
			result = mid;
			if (minimum) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		else if (x > A[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return result;
}

int main() {
	int A[] = {1,1,1,2,2,2,2,3,3,4,4,4,4,4,5,6,6,6,7,7,8,8,8,8,8,9,9};
	int n = sizeof(A) / sizeof(A[0]);
	int x, min_index, max_index;

	cout << "Enter the element : ";
	cin >> x;
	min_index = findMinimumIndex(A, n, x);
	max_index = findMaximumIndex(A, n, x);
	if (min_index != -1 && max_index != -1) {
		cout << "Minimum Index (findMinimumIndex): " << min_index << endl;
		cout << "Maximum Index (findMaximumIndex): " << max_index << endl;
	}

	min_index = findMinMaxIndex(A, n, x, true);
	max_index = findMinMaxIndex(A, n, x, false);
	if (min_index != -1 && max_index != -1) {
		cout << "Minimum Index (findMinMaxIndex): " << min_index << endl;
		cout << "Maximum Index (findMinMaxIndex): " << max_index << endl;
	}

	return 0;
}