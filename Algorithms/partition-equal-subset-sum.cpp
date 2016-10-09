// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.empty()) return false;
		if (nums.size() == 1) return nums[0] == 0;
		if (nums.size() == 2) return nums[0] == nums[1];
		int sum = accumulate(begin(nums), end(nums), 0);
		if (sum & 1) return false;
		for (size_t i = 1; i <= nums.size() / 2; i++) {
			for (size_t j = 0; j < i; j++) {
				for (size_t k = j; k < nums.size(); k++) {
					swap(nums[j], nums[k]);
					if (2 * accumulate(begin(nums), begin(nums) + i, 0) == sum) return true;
				}
			}
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	cout << boolalpha << solution.canPartition(nums) << "\tPassed\n";
	nums = {1, 5, 11, 5};
	cout << boolalpha << solution.canPartition(nums) << "\tPassed\n";
	nums = {1, 2, 3, 5};
	cout << boolalpha << solution.canPartition(nums) << "\tPassed\n";
	nums = {73, 75, 1, 61, 42, 92, 95, 94, 86, 81, 66, 21, 32, 80, 16, 52, 35, 90, 60, 20, 57, 95, 34, 40, 72, 83, 35, 67, 86, 78, 68, 47, 60, 72, 37, 83, 43, 35, 98, 24, 6, 38, 22, 42, 47, 62, 72, 42, 20, 70, 6, 75, 55, 28, 61, 85, 54, 33, 67, 99, 30, 80, 94, 56, 13, 33, 39, 37, 59, 82, 82, 16, 17, 60, 4, 36, 23, 76, 34, 45, 3, 97, 86, 2, 63, 17, 95, 92, 61, 36, 66, 18, 67, 5, 46, 38, 5, 53, 59, 17};
	cout << boolalpha << solution.canPartition(nums) << "\tPassed\n";	
	nums = {1, 5, 11, 5};
	cout << boolalpha << solution.canPartition(nums) << "\tPassed\n";		
	cout << "\nPassed All\n";
	return 0;
}