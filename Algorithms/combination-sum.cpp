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
		vector<vector<int>> result;
		if (target <= 0 || candidates.empty())
			return result;
		sort(begin(candidates), end(candidates));
		if (target < candidates.front())
			return result;
		auto lb = lower_bound(begin(candidates), end(candidates), target);
		if (*lb == target) {
			result = {{target}};
		}
		for (auto it = begin(candidates); it < lb; ++it) {
			vector<vector<int>> v = this->combinationSum(candidates, target - *it);
			if (v.empty()) 
				continue;
			else {
				for (auto& i : v) {
					auto pos = lower_bound(begin(i), end(i), *it);
					i.insert(pos, *it);
					if (find(begin(result), end(result), i) == end(result))
						result.push_back(i);
					else
						continue;
				}
			}
		}
		return result;
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
	getchar();
	return 0;
}