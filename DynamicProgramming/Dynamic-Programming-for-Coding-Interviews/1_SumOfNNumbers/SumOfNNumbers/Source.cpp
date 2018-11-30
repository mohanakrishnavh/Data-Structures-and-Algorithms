#include <iostream>

using namespace std;

// Iterative
int sumIterative(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

// Recursive
int sumRecursive(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return n + sumRecursive(n - 1);
	}
}

int main() {
	int n;
	cout << "Enter the number : ";
	cin >> n;
	cout << "Sum(Recursive) : " << sumRecursive(n) << endl;
	cout << "Sum(Iterative) : " << sumIterative(n) << endl;
	return 0;
}