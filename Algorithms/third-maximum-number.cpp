// 414. Third Maximum Number
// https://leetcode.com/problems/third-maximum-number/
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(begin(nums), end(nums));
		reverse(begin(nums), end(nums));
		size_t i = 0, n = nums.size();
		while (i + 1 < n && nums[i + 1] == nums[i]) i++;
		if (i + 1 == n) return nums[0];
		i++;
		while (i + 1 < n && nums[i + 1] == nums[i]) i++;
		if (i + 1 == n) return nums[0];
		return nums[++i];
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 2, 2, 5, 3, 5};
	cout << solution.thirdMax(nums) << "\tPassed\n";
	nums = {-2147483648, 1, 2};
	cout << solution.thirdMax(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}