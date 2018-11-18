#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int> &nums) {
	int size = nums.size();
	
	if (size == 0){
		return 0;
	}

	int i = 0;
	for (int j = 1; j < nums.size(); j++) {
		if (nums[j] != nums[i]) {
			i++;
			nums[i] = nums[j];
		}
	}

	return i+1;
}

int main() {
	vector<int> vect{ 1, 1, 2 };
	int unique_size = remove_duplicates(vect);
	cout << unique_size;
	return 0;
}