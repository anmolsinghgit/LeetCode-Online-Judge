// 334. Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence/
// https://discuss.leetcode.com/topic/37281/clean-and-short-with-comments-c
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int c1 = INT_MAX, c2 = INT_MAX;
		for (const auto& i : nums) {
			if (i <= c1)
				c1 = i;
			else if (i <= c2)
				c2 = i;
			else
				return true;
		}
		return false;
	}
};
// class Solution {
// public:
// 	bool increasingTriplet(vector<int>& nums) {
// 		vector<int> result;
// 		for (const auto& i : nums) {
// 			vector<int>::iterator it = lower_bound(begin(result), end(result), i);
// 			if (it == end(result)) result.push_back(i);
// 			else *it = i;
// 			if (result.size() >= 3) return true;
// 		}
// 		return false;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums {1, 2, 3, 4, 5};
	cout << boolalpha << solution.increasingTriplet(nums) << "\tPassed\n";
	nums = {5, 4, 3, 2, 1};
	cout << boolalpha << solution.increasingTriplet(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}