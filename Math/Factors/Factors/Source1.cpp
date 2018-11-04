#include <iostream>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

set<int> factors(int n) {
	set<int> result;
	result.insert(1);
	result.insert(n);
	for (int i = 2; i < sqrt(n); i++) {
		if (n%i == 0) {
			result.insert(i);
			if (i != sqrt(n)) {
				result.insert(n / i);
			}
		}
	}
	return result;
}

int main() {
	int n;
	cout << "Enter the number : ";
	cin >> n;

	set<int> result = factors(n);
	set<int>:: iterator itr;

	cout << "\nFactors of " << n << " : ";
	for (itr = result.begin(); itr != result.end(); itr++) {
		cout << *itr << " ";
	}
	return 0;
}