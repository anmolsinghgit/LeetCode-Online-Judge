// 78. Subsets
// https://leetcode.com/problems/subsets/
// https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
		sort(begin(nums), end(nums));
		this->subsets(0, path, result, nums);
		return result;
	}
private:
	void subsets(const int& start, vector<int>& path, vector<vector<int>>& result, const vector<int>& nums) {
		result.push_back(path);
		for (int i = start; i < nums.size(); ++i) {
			path.push_back(nums[i]);
			this->subsets(i + 1, path, result, nums);
			path.pop_back();
		}
		return;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1,2,3};
	for (const auto& i : solution.subsets(nums)) {
		for (const auto& j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}