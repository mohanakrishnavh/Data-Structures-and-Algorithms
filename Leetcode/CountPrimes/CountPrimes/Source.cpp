#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
	int count = 0;
	vector<int> primes(n);
	fill(primes.begin(), primes.end(), 1);

	int sqrt_n = static_cast<int>(sqrt(n));
	primes[0] = 0;
	count++;
	primes[1] = 0;
	count++;

	for (int i = 2; i <= sqrt_n; i++) {
		if (primes[i] == 1) {
			for (int j = 2; i*j < n; j++) {
				if (primes[i*j] != 0) {
					primes[i*j] = 0;
					count++;
				}
			}
		}
	}
	return (n - count);
}

int main() {
	int n, no_of_primes;
	cout << "Enter the number : ";
	cin >> n;
	no_of_primes = countPrimes(n);
	cout << "Count of primes : " << no_of_primes;

	return 0;
}