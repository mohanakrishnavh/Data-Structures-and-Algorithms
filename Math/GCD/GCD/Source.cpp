#include <iostream>

using namespace std;

/*
Time Complexity : O(log b)
*/

//Euclid's Algorithm
int euclid_gcd(int a, int b) {
	int dividend = a;
	int divisor = b;
	while (divisor != 0) {
		int remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}
	return dividend;
}