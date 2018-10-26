#include <iostream>
#include <map>

using namespace std;

int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	return (fibonacci(n - 1) + fibonacci(n - 2));
}

int fibonacci_memoized(int n) {
	map<int, int> cache;
	if (!(cache.count(n) > 0)) {
		if (n <= 1) {
			cache[n] = n;
		}
		else {
			cache[n] = fibonacci_memoized(n - 1) + fibonacci_memoized(n - 2);
		}
	}
	return cache[n];
}

int fibonacci_iterative(int n) {
	if (n <= 1) {
		return n;
	}
	int f, f_minus_2 = 0, f_minus_1 = 1;
	for (int i = 2; i <= n; i++) {
		f = f_minus_1 + f_minus_2;
		f_minus_2 = f_minus_1;
		f_minus_1 = f;
	}
	return f;
}

int main() {
	int n;
	cout << "Enter the number : ";
	cin >> n;
	n++;
	int result = fibonacci(n);
	cout << "\nFibonacci(" << n << ") :" << result << endl;

	result = fibonacci_memoized(n);
	cout << "\nFibonacci(" << n << ") Memoized :" << result << endl;

	result = fibonacci_iterative(n);
	cout << "\nFibonacci(" << n << ") Iterative :" << result << endl;
	return 0;
}