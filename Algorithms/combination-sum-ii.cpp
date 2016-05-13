// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, const int& target) {
		vector<vector<int>> result;
		if (target <= 0 || candidates.empty())
			return result;
		sort(begin(candidates), end(candidates));
		if (target < candidates.front())
			return result;
		auto lb = lower_bound(begin(candidates), end(candidates), target);
		if (*lb == target)
			result = {{target}};
		for (auto it = begin(candidates); it < lb; ++it) {
			vector<int> t(begin(candidates), end(candidates));
			t.erase(begin(t) + distance(begin(candidates), it));
			vector<vector<int>> x = this->combinationSum2(t, target - *it);
			if (x.empty())
				continue;
			else {
				for (auto& i : x) {
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
	vector<int> candidates = {10,1,2,7,6,1,5};
	int target = 8;
	cout << '[';
	for (const auto& i : solution.combinationSum2(candidates, target)) {
		cout << '\n';
		cout << '\t';
		cout << '[';
		cout << '\t';
		for (const auto& j : i) {
			cout << j << '\t';
		}
		cout << ']';
		cout << '\n';
	}
	cout << "\nPassed\n";
	getchar();
	return 0;
}