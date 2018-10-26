#include <iostream>

using namespace std;

int* climbingStairs(int n) {
	int* S = new int[n + 1];
	S[1] = 1;
	S[2] = 2;
	S[3] = 4;
	for (int i = 4; i <= n; i++) {
		S[i] = S[i - 1] + S[i - 2] + S[i - 3];
	}
	return S;
}

int main() {
	int n;
	cout << "Enter the value of n: ";
	cin >> n;
	int* result = new int[n + 1];
	result = climbingStairs(n);
	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}
	return 0;
}