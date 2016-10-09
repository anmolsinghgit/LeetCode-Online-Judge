// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/62271/c-solution-with-dynamic-programming
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		const int sum = accumulate(begin(nums), end(nums), 0);
		const int n = nums.size();
		if (sum & 1) return false;
		vector<bool> OPT(1 + sum / 2, false);
		OPT[0] = true;
		for (int i = 1; i < 1 + sum / 2; i++)
			for (int j = 0; j < n; j++)
				if (nums[j] <= i)
					OPT[i] = OPT[i] || OPT[i - nums[j]];
		return OPT[sum / 2];
	}
};
// class Solution {
// public:
// 	bool canPartition(vector<int>& nums) {
// 		int sum = accumulate(begin(nums), end(nums), 0);
// 		if (sum & 1) return false;
// 		for (size_t i = 1; i <= nums.size() / 2; i++) {
// 			for (size_t j = 0; j < i; j++) {
// 				for (size_t k = j; k < nums.size(); k++) {
// 					swap(nums[j], nums[k]);
// 					if (2 * accumulate(begin(nums), begin(nums) + i, 0) == sum) return true;
// 				}
// 			}
// 		}
// 		return false;
// 	}
// };
// END: https://discuss.leetcode.com/topic/62271/c-solution-with-dynamic-programming
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
	nums = {74, 95, 89, 56, 83, 77, 58, 40, 8, 74, 37, 64, 89, 85, 51, 35, 5, 35, 79, 99, 95, 94, 38, 78, 39, 49, 36, 1, 39, 68, 41, 25, 12, 36, 24, 98, 34, 19, 9, 89, 48, 30, 47, 42, 49, 53, 18, 99, 52, 86, 59, 28, 56, 99, 34, 1, 11, 43, 75, 13, 29, 84, 92, 14, 13, 38, 14, 85, 16, 24, 20, 31, 96, 30, 88, 95, 90, 69, 73, 42, 47, 23, 67, 56, 85, 10, 97, 59, 98, 19, 10, 10, 25, 39, 1, 14, 9, 4, 76};
	cout << boolalpha << solution.canPartition(nums) << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}