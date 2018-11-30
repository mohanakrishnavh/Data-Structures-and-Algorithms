#include <iostream>

using namespace std;



//Recursive
int factorialOfN2RecursiveHelper(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return n * factorialOfN2RecursiveHelper(n - 1);
	}
}

int factorialOfN2Recursive(int n) {
	n = n * n;
	int fact = factorialOfN2RecursiveHelper(n);
	return fact;
}

//Iterative
int factorialOfN2Iterative(int n) {
	int fact = 1;
	for (int i = 1; i <= (n*n); i++) {
		fact *= i;
	}
	return fact;
}


int main() {
	int n;
	cout << "Enter the number : ";
	cin >> n;
	cout << endl;
	cout << "Factorial of n^2 (Iterative) : " << factorialOfN2Iterative(n) << endl;
	cout << "Factorial of n^2 (Recursive) : " << factorialOfN2Iterative(n) << endl;

	return 0;
}