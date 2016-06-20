// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		sort(begin(candidates), end(candidates));
		vector<int> path;
		this->combinationSum2(0, path, target, result, candidates);
		return result;
	}
	void combinationSum2(int start, vector<int>& path, int target, vector<vector<int>>& result, const vector<int>& candidates) {
		if (target < 0) 
			return;
		else if (target == 0) {
			if (path.empty())
				return;
			else {
				result.push_back(path);
				return;
			}
		}
		else {
			for (int i = start; i < candidates.size(); i++) {
				if (i > start && candidates[i] == candidates[i - 1])
					continue;
				path.push_back(candidates[i]);
				this->combinationSum2(i + 1, path, target - candidates[i], result, candidates);
				path.pop_back();
			}
			return;
		}

	}
};
int main(void) {
	Solution solution;
	vector<int> candidates = {14,22,8,31,30,26,9,34,20,13,10,22,6,12,18,22,28,19,14,17,24,24,22,14,27,30,6,23,25,14,33,5,23,7,23,18,28,20,9,5,20,14,22,21,21,6,9,6,12,10,19,31,21,28,32,14,23,33,32,14};
	int target = 29;
	for (const auto& i : solution.combinationSum2(candidates, target)) {
		for (const auto& j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	return 0;
}
