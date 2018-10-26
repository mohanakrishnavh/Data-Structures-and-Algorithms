#include <iostream>

using namespace std;

int findRoatationCount(int A[], int n) {
	int start = 0, end = n - 1;
	while (start <= end) {
		//case 1
		if (A[start] <= A[end]) {
			return start;
		}
		//case2
		int mid = static_cast<int>((start + end) / 2);
		int next = (mid + 1) % n;
		int prev = (mid + n - 1) % n;
		if ((A[mid] <= A[next]) && (A[mid] <= A[prev])) {
			return mid;
		}
		//case 3
		else if (A[mid] <= A[end]) {
			end = mid - 1;
		}
		//case 4
		else if (A[mid] >= A[start]) {
			start = mid + 1;
		}
	}
	return -1;
}

int main() {
	int A[] = {12,1,2,3,4,5,6,7,8,9,10,11};
	int n = sizeof(A) / sizeof(A[0]);
	cout << "Array is rotated " << findRoatationCount(A, n) << " times.";
	return 0;
}