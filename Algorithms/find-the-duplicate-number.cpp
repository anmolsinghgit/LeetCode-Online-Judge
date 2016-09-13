// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// https://www.youtube.com/watch?v=FkBm3NeWqak
// https://en.wikipedia.org/wiki/Cycle_detection
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = nums[0], fast = nums[0];
		do {
			slow = nums[slow];
			fast = nums[fast];
			fast = nums[fast];
		} while (slow != fast);
		slow = nums[0];
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];			
		}
		return slow;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << solution.findDuplicate(nums) << "\tPassed\n";
	nums = {1, 3, 4, 2, 2};
	cout << solution.findDuplicate(nums) << "\tPassed\n";
	nums = {1, 3, 4, 2, 1};
	cout << solution.findDuplicate(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}