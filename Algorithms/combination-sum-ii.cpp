// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& v, const int& target) {
		vector<vector<int>> result;
		if (target <= 0 || v.empty())
			return result;
		sort(begin(v), end(v));
		if (target < v.front())
			return result;
		auto lb = lower_bound(begin(v), end(v), target);
		if (*lb == target)
			result = {{target}};
		for (auto it = begin(v); it < lb; ++it) {
			vector<int> t(begin(v), end(v));
			t.erase(begin(t) + distance(begin(v), it));
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
	vector<int> v = {10,1,2,7,6,1,5};
	int target = 8;
	cout << '[';
	for (const auto& i : solution.combinationSum2(v, target)) {
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