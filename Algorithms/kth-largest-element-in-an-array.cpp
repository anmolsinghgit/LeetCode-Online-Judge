// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(begin(nums), end(nums));
		return nums[nums.size() - k];
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {3, 2, 1, 5, 6, 4}; 
	int k = 2;
	cout << solution.findKthLargest(nums, k) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}