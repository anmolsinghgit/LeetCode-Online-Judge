// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/
// https://discuss.leetcode.com/topic/14944/single-line-c-solution-60ms
#include <iostream>
#include <vector>
#include <unordered_set>
#include <iterator>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return nums.size() > unordered_set<int>(begin(nums), end(nums)).size();
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1, 22, 33, 2, 2, 19};
	cout << boolalpha << solution.containsDuplicate(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}