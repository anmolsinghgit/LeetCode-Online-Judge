// 136. Single Number
// https://leetcode.com/problems/single-number/
// https://discuss.leetcode.com/topic/1916/my-o-n-solution-using-xor
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (const auto &i : nums) result ^= i;
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 1, 2, 2, 3};
	cout << solution.singleNumber(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}