// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int search(const vector<int>& nums, const int& target) {
		if (nums.empty()) {
			return -1;
		}
		if (nums.size() == 1) {
			return nums.front() == target ? 0 : -1;
		}
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (mid >= 1 && nums[mid - 1] == target) {
				return mid - 1;
			}
			if (mid + 1 < nums.size() && nums[mid + 1] == target) {
				return mid + 1;
			}
			if (nums[mid] > nums.front()) {
				if (nums.front() <= target && target < nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if (nums[mid] < target && target <= nums.back()) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
		return nums[mid] == target ? mid : -1;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums({4, 5, 6, 7, 0, 1, 2});
	for (int i = 0; i < nums.size(); ++i) {
		if (i ^ solution.search(nums, nums[i])) {
			cout << "\nError\n";
			return 0;
		}
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}