#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(n)
Note : unorodered_set can also be used
*/

bool containsDuplicate(vector<int>& nums) {
	unordered_map<int, int> nums_count;
	for (int i = 0; i < nums.size(); i++) {
		if (nums_count.count(nums[i]) > 0) {
			return true;
		}
		else {
			nums_count[nums[i]] = 1;
		}
	}
	return false;
}

int main() {
	//vector<int> nums{ 1,2,3,1};
	//vector<int> nums{ 1,2,3,4 };
	vector<int> nums{ 1,1,1,3,3,4,3,2,4,2 };
	bool result;
	
	cout << boolalpha;
	result = containsDuplicate(nums);
	cout << result << endl;

	return 0;
}