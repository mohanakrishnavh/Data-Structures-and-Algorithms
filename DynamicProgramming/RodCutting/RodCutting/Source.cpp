#include <iostream>
#include <vector>

using namespace std;

int rodCutting(int n, vector<int>& prices) {
	vector<int> R(n + 1);
	R[0] = 0;
	for (int i = 1; i <= n; i++) {
		int max_val = -1;
		for (int j = 1; j <= i; j++) {
			int temp = prices[j - 1] + R[i - j];
			if (temp > max_val) {
				max_val = temp;
			}
		}
		R[i] = max_val;	
	}
	return R[n];
}

int main() {
	vector<int> prices{ 1, 5, 8, 9, 10 };
	cout << rodCutting(5, prices);

	return 0;
}