// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// https://discuss.leetcode.com/topic/18583/accepted-clean-java-o-n-solution-two-pointers
// https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int i = 0, j = 0, sum = 0, result = numeric_limits<int>::max();
		while (j < nums.size()) {
			sum += nums[j++];
			while (sum >= s) {
				result = min(result, j - i);
				sum -= nums[i++];
			}
		}
		return result == numeric_limits<int>::max() ? 0 : result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {2, 3, 1, 2, 4, 3};
	int s = 7;
	cout << solution.minSubArrayLen(s, nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}