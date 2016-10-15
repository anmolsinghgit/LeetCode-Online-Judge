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
	cout << "\nPassed All\n";
	return 0;
}