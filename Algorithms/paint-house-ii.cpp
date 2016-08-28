// 265. Paint House II
// https://leetcode.com/problems/paint-house-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>
using namespace std;
class Solution {
public:
	int minCostII(vector<vector<int>>& costs) {
		if (costs.empty()) return 0;
		const size_t &n = costs.size();
		const size_t &k = costs.front().size();
		for (size_t i = 1; i < n; ++i) {
			vector<int> v(k, INT_MAX);
			int left = INT_MAX, right = INT_MAX;
			for (size_t j = 0; j < k; ++j) {
				v[j] = min(v[j], left);
				left = min(left, costs[i - 1][j]);
				v[k - 1 - j] = min(v[k - 1 - j], right);
				right = min(right, costs[i - 1][k - 1 - j]);
			}
			for (size_t j = 0; j < k; ++j)
				costs[i][j] += v[j];
		}
		return *min_element(begin(costs.back()), end(costs.back()));
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> costs = {{20, 18, 4}, {9, 9, 10}};
	cout << solution.minCostII(costs) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}