// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
	int maxSubArray(const vector<int>& nums) {
		int result = INT_MIN;
		int sum = 0;
		for (const auto& i : nums) {
			sum	= max(sum + i, i);
			result = max(result, sum);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	if (solution.maxSubArray(nums) == 6) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	return 0;
}