#include <iostream>
#include <vector>

using namespace std;


//Sieve of Eratosthenes
vector<int> generate_primes(int n) {
	vector<int> primes(n);
	fill(primes.begin(), primes.end(), 1);

	int sqrt_n = static_cast<int>(sqrt(n));
	primes[0] = 0;
	primes[1] = 0;

	for (int i = 2; i <= sqrt_n ; i++) {
		if (primes[i] == 1) {
			for (int j = 2; i*j < n; j++) {
				primes[i*j] = 0;
			}
		}
	}
	return primes;

}

int main() {
	int n;
	vector<int> result;
	cout << "Enter the number: ";
	cin >> n;
	result = generate_primes(n);
	cout << "Prime Number less than " << n << " :" << endl;
	for (int i=0; i < result.size(); i++) {
		if (result[i] == 1) {
			cout << i << " ";
		}
	}

	return 0;
}

