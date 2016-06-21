// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, const int& target) {
		sort(begin(candidates), end(candidates));
		vector<vector<int>> result;
		vector<int> path; 
		this->combinationSum(result, 0, path, target, candidates);
		return result;
	}
private:
	void combinationSum(vector<vector<int>>& result, const int& start, vector<int>& path, const int& target, const vector<int>& candidates) {
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
				path.push_back(candidates[i]);
				this->combinationSum(result, i, path, target - candidates[i], candidates);
				path.pop_back();
			}
			return;
		}
	}
};
int main(void) {
	Solution solution;

	// vector<int> candidates = {2,3,6,7};
	// int target = 7;

	vector<int> candidates = {4, 5, 2};
	int target = 16;	
	cout << '[';
	for (const auto& i : solution.combinationSum(candidates, target)) {
		cout << '\n';
		cout << '\t';
		cout << '[';
		cout << '\t';
		for (const auto& j : i)
			cout << j << '\t';
		cout << ']';
		cout << '\n';
	}
	cout << ']';
	cout << "\nPassed\n";
	return 0;
}
