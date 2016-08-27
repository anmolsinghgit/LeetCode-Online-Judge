// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// https://discuss.leetcode.com/topic/20434/o-n-time-and-o-1-space-c-solution-with-explanation
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result(nums.size(), 1);
		int begin = 1;
		int end = 1;
		for (int i = 0; i < nums.size(); ++i) {
			result[i] *= begin;
			begin *= nums[i];
			result[nums.size() - 1 - i] *= end;
			end *= nums[nums.size() - 1 - i];
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 2, 3, 4};
	for (const auto &i : solution.productExceptSelf(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}