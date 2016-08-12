// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		const int n = nums.size();
		if (n == 1) return 0;
		if (n == 2) return nums[0] > nums[1] ? 0 : 1;
		int left = 0;
		int right = n - 1;
		int mid = left + (right - left) / 2;
		if (nums[left] > nums[left + 1]) return left;
		if (nums[right - 1] < nums[right]) return right;
		while (left < right) {
			if (mid - 1 >= 0 && mid + 1 < n && nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;
			if (left - 1 >= 0 && left + 1 < n && nums[left - 1] < nums[left] && nums[left] > nums[left + 1]) return left;
			if (right - 1 >= 0 && right + 1 < n && nums[right - 1] < nums[right] && nums[right] > nums[right + 1]) return right;
			if (nums[left] < nums[mid] && nums[mid] > nums[right]) {
				if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
					++left;
					right = mid - 1;
					mid = left + (right - left) / 2;
					continue;
				}
				if (mid + 1 < n && nums[mid] < nums[mid + 1]) {
					--right;
					left = mid + 1;
					mid = left + (right - left) / 2;
					continue;					
				}
			}
			++left;
			--right;
			continue;
		}
		return mid;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 2, 3, 1};
	cout << solution.findPeakElement(nums) << "\tPassed\n";
	nums = {1, 2, 3, 4, 3, 2};
	cout << solution.findPeakElement(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}