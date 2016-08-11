// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		const int n = nums.size();
		if (n == 1) return nums[0];
		int result = numeric_limits<int>::min();
		int m1 = 1;
		int m2 = 1;
		for (const auto &i : nums) {
			int x1 = max(i, m1 * i);
			x1 = max(x1, m2 * i);
			int x2 = min(i, m1 * i);
			x2 = min(x2, m2 * i);
			m1 = x1;
			m2 = x2;
			result = max(result, m1);
			result = max(result, m2);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {2, 3, -2, 4};
	cout << solution.maxProduct(nums) << "\tPassed\n";
	nums = {-2, 3, -4};
	cout << solution.maxProduct(nums) << "\tPassed\n";
	nums = {0, 2};
	cout << solution.maxProduct(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}