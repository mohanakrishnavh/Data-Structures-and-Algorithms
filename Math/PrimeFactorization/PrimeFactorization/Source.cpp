#include <iostream>
#include <utility>
#include <vector>
#include <iterator>


using namespace std;

vector<pair<int,int>> primeFactors(int n) {
	vector<pair<int, int>> result;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			int count = 0;
			while (n%i == 0) {
				n = n / i;
				count++;
			}
			result.push_back(make_pair(i, count));
		}
	}
	if (n != 1) {
		result.push_back(make_pair(n, 1));
	}
	return result;
}

bool isSqure(vector<pair<int,int>> prime_factors) {
	vector<pair<int, int>>::iterator itr;
	pair<int, int> current;
	bool result = true;
	for (itr = prime_factors.begin(); itr != prime_factors.end(); itr++) {
		current = *itr;
		if (current.second % 2 != 0) {
			result = false;
		}
	}
	return result;
}

int main() {
	int n;
	vector<pair<int, int>> result;
	pair<int, int> current_pair;
	cout << "Enter the number: ";
	cin >> n;
	result = primeFactors(n);
	vector<pair<int, int>>::iterator itr;
	for (itr = result.begin(); itr != result.end(); itr++) {
		current_pair = *itr;
		cout << "(" << current_pair.first << "," << current_pair.second << ")";
		cout << "\n";
	}

	cout << boolalpha;
	cout << "\nIs Square ? :" << isSqure(result);

	return 0;
}

