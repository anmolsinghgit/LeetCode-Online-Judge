// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/
// https://discuss.leetcode.com/topic/15045/c-solution-with-unordered_set
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> hashSet;
		for (size_t i = 0; i < nums.size(); ++i) {
			if (i > k) hashSet.erase(nums[i - k - 1]);
			if (hashSet.count(nums[i])) return true;
			hashSet.insert(nums[i]);
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 22, 33, 2, 2, 19};	
	cout << boolalpha << solution.containsNearbyDuplicate(nums, 2) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}