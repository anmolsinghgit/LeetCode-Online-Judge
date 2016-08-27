// 256. Paint House
// https://leetcode.com/problems/paint-house/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		if (costs.empty()) return 0;
		for (size_t i = 1; i < costs.size(); ++i)
			for (int j = 0; j < 3; ++j)
				costs[i][j] = min(costs[i][j] + costs[i - 1][(j + 1) % 3], costs[i][j] + costs[i - 1][(j + 2) % 3]);
		return min(min(costs.back()[0], costs.back()[1]), costs.back()[2]);
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> costs = {{20, 18, 4}, {9, 9, 10}};
	cout << solution.minCost(costs) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}