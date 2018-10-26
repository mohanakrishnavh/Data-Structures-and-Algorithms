#include <iostream>

using namespace std;

bool isPrime(int n) {
	if (n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}

	int sqrt_n = static_cast<int>(sqrt(n));
	for (int i = 3; i <= sqrt_n; i++) {
		if ((n % i) == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cout << "Enter the number :";
	cin >> n;
	bool result = isPrime(n);
	cout << result;
	return 0;
}