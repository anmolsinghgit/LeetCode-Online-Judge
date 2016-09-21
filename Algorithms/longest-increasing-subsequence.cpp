// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		const int n = nums.size();
		vector<int> OPT(n + 1, 0);
		int result = 0;
		for (int i = n - 1; i >= 0; --i) {
			int tmp = 0;
			for (int j = 1; i + j < n; ++j)
				if (nums[i + j] > nums[i])
					tmp = max(tmp, OPT[i + j]);
			result = max(result, OPT[i] = (1 + tmp));
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << solution.lengthOfLIS(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}