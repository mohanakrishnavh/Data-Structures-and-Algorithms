#include <iostream>

using namespace std;

int circularArraySearch(int A[], int n, int x) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = static_cast<int>((start + end) / 2);
		// case 1 : found x
		if (x == A[mid]) {
			return mid;
		}
		// case 2 : right half is sorted
		if (A[mid] <= A[end]) {
			if (x > A[mid] && x <= A[end]) {
				start = mid + 1; //search in right sorted half
			}
			else {
				end = mid - 1; //search in left half
			}
		}
		// case 3 : left half is sorted
		else if (A[start] <= A[mid]) {
			if (x >= A[start] && x < A[mid]) {
				end = mid - 1; //search in left sorted half
			}
			else {
				start = mid + 1; //search in right sorted half 
			}
		}
	}
	return - 1;
}

int main() {
	int A[] = { 12, 14, 18, 21, 3, 6, 8, 9 };
	int x;
	int n = sizeof(A) / sizeof(A[0]);
	cout << "Enter the number : ";
	cin >> x;
	int result = circularArraySearch(A, n , x);
	if (result != -1) {
		cout << "Element found at index : " << result << endl;
	}
	else {
		cout << "Element not found!";
	}

	return 0;
}