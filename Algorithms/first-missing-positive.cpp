// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/
// https://leetcode.com/discuss/24013/my-short-c-solution-o-1-space-and-o-n-time
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (auto& i : nums) {
			while (i > 0 && i <= nums.size() && nums[i - 1] != i)
				swap(i, nums[i - 1]);
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return nums.size() + 1;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {3,4,-1,1};
	cout << solution.firstMissingPositive(nums);
	cout << "\nPassed\n";
	return 0;
}
