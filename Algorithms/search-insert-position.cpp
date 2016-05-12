//35. Search Insert Position
//https://leetcode.com/problems/search-insert-position/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int searchInsert(const vector<int>& nums, const int& target) {
		int result = 0;
		if (nums.back() < target)
			result = nums.size();
		else {
			auto first = lower_bound(nums.begin(), nums.end(), target);
			result = distance(nums.begin(), first);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = { 1,3,5,6 };
	//int target = 5;
	//int target = 2;
	//int target = 7;
	int target = 0;
	cout << solution.searchInsert(nums, target);
	cout << "\nPassed\n";
	getchar();
	return 0;
}
