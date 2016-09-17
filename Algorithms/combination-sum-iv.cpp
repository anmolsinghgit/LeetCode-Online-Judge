// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/
// https://discuss.leetcode.com/topic/52186/my-3ms-java-dp-solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		sort(begin(nums), end(nums));
		vector<int> OPT(target + 1, 0);
		OPT[0] = 1;
		for (int i = 1; i < target + 1; ++i) {
			for (const auto &j : nums) {
				if (j > i) break;
				OPT[i] += OPT[i - j];
			}
		}
		return OPT.back();
	}
};
// class Solution {
// public:
// 	int combinationSum4(vector<int>& nums, int target) {
// 		sort(begin(nums), end(nums));
// 		while (!nums.empty() && nums.back() > target) nums.pop_back();
// 		if (nums.empty()) return 0;
// 		const int n = nums.size();
// 		vector<vector<int>> OPT(target + 1, vector<int>(n, 0));
// 		for (int i = 0; i < n; ++i) OPT[nums[i]][i] = 1;
// 		for (int i = 1; i < target + 1; ++i)
// 			for (int j = 0; j < n; ++j)
// 				OPT[i][j] = i > nums[j] ? accumulate(begin(OPT[i - nums[j]]), end(OPT[i - nums[j]]), 0) : OPT[i][j];
// 		return accumulate(begin(OPT.back()), end(OPT.back()), 0);
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums = {1, 2, 3};
	cout << solution.combinationSum4(nums, 4) << "\tPassed\n";
	nums = {9};
	cout << solution.combinationSum4(nums, 3) << "\tPassed\n";
	nums = {};
	cout << solution.combinationSum4(nums, 3) << "\tPassed\n";
	nums = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	cout << solution.combinationSum4(nums, 10) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}