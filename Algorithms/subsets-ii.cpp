// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/
// https://discuss.leetcode.com/topic/13543/accepted-10ms-c-solution-use-backtracking-only-10-lines-easy-understand/2
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
		sort(begin(nums), end(nums));
		this->subsetsWithDup(0, path, result, nums);
		return result;
	}
private:
	void subsetsWithDup(const int& start, vector<int>& path, vector<vector<int>>& result, const vector<int>& nums) {
		result.push_back(path);
		for (int i = start; i < nums.size(); ++i) {
			if (i == start || nums[i] != nums[i - 1]) {
				path.push_back(nums[i]);
				this->subsetsWithDup(i + 1, path, result, nums);
				path.pop_back();
			}
		}
		return;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1,2,2};
	for (const auto& i : solution.subsetsWithDup(nums)) {
		for (const auto& j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}