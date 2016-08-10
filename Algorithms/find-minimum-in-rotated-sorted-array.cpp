// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		const int n = nums.size();
		if (n == 1) return nums[0];
		int i = 0, j = n - 1;
		if (nums[i] < nums[j]) return nums[i];
		int mid = i + (j - i) / 2;
		while (i < j) {
			if (i + 1 == j) return min(nums[i], nums[j]);
			if (nums[mid] > nums[0]) {
				if (mid + 1 < n && nums[mid + 1] < nums[mid]) return nums[mid + 1];
				i = mid + 1;
			}
			else {
				if (mid - 1 >= 0 &&nums[mid - 1] > nums[mid]) return nums[mid];
				j = mid - 1;
			}
			mid = i + (j - i) / 2;
		}
		return nums[mid];
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	cout << solution.findMin(nums) << '\n';
	cout << "\nPassed\n";
	nums = {2, 1};
	cout << solution.findMin(nums) << '\n';
	cout << "\nPassed\n";
	nums = {1, 2, 3};
	cout << solution.findMin(nums) << '\n';
	cout << "\nPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}