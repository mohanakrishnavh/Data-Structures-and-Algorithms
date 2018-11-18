#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Time Complexity : O(n + m)
Space Complexity : O(max(n, m)
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> result;
	unordered_map<int, int> count_map;

	for (int i = 0; i < nums1.size(); i++) {
		count_map[nums1[i]] = 1;
	}

	for (int j = 0; j < nums2.size(); j++) {
		if (count_map.count(nums2[j]) > 0) {
			result.insert(nums2[j]);
		}
	}

	vector<int> output(result.begin(), result.end());
	return output;
}

int main() {
	vector<int> nums1{ 1,2,2,1 };
	vector<int> nums2{ 2,2 };
	vector<int> result = intersection(nums1, nums2);

	cout << "Intersection : ";
	for (auto itr = result.begin(); itr != result.end(); itr++) {
		cout << *itr << " ";
	}
	cout << "\n";

	return 0;
}