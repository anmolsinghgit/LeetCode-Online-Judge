// 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int left = 0;
		int right = nums.size() - 1;
		if (nums[left] < nums[right]) return nums[left];
		int mid = left + (right - left) / 2;
		while (left < right) {
			if (nums[left] < nums[right]) return nums[left];
			if (nums[left] < nums[mid]) {
				while (mid + 1 <= right && nums[mid + 1] == nums[mid]) ++mid;
				if (mid + 1 <= right && nums[mid] > nums[mid + 1]) return nums[mid + 1];
				if (mid + 1 <= right && nums[mid] < nums[mid + 1]) {
					left = mid + 1;
					mid = left + (right - left) / 2;
					continue;
				}
				++left;
				mid = left + (right - left) / 2;
				continue;				
			}
			if (nums[left] == nums[mid]) {
				if (mid + 1 <= right && nums[mid] > nums[mid + 1]) return nums[mid + 1];
				if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) return nums[mid];
				++left;
				mid = left + (right - left) / 2;
				continue;
			}
			while (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) --mid;
			if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) return nums[mid];
			if (mid - 1 >= 0 && nums[mid - 1] < nums[mid]) {
				right = mid - 1;
				mid = left + (right - left) / 2;
				continue;				
			}
			--right;
			mid = left + (right - left) / 2;
			continue;		
		}
		return nums[mid];
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	cout << solution.findMin(nums) << '\n';
	cout << "\nPassed\n";
	nums = {10, 1, 10, 10, 10};
	cout << solution.findMin(nums) << '\n';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}