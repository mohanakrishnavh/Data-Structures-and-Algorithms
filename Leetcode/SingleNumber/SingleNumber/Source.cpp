#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
Approach : Hash Map or Hash Set
Time Complexity : O(n)
Space Complexity : O(n) 
*/
int singleNumber(vector<int>& nums) {
	unordered_set<int> unique;
	for (int i = 0; i < nums.size(); i++) {
		auto itr = unique.find(nums[i]);
		if (itr != unique.end()) {
			unique.erase(itr);
		}
		else {
			unique.insert(nums[i]);
		}
	}

	auto result_itr = unique.begin();
	int result = *result_itr;
	return result;
}


/*
Approach : Bit Manipulation
Time Complexity : O(n)
Space Complexity : O(1)
*/
int singleNumber2(vector<int>& nums) {
	int unique = 0;
	for (int i = 0; i < nums.size(); i++) {
		unique ^= nums[i];
	}
	return unique;
}


int main() {
	vector<int> nums{ 2,2,1 };
	int result = singleNumber2(nums);
	cout << "Unique Element : " << result << endl;
	return 0;
}