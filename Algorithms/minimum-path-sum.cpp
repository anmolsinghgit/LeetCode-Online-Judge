// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(const vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		if (grid.size() == 1 && grid.front().size() == 1)
			return grid[0][0];
		int m(grid.size());
		int n(grid.front().size());
		vector<vector<int>> OPT(m, vector<int>(n, 0));
		OPT[0][0] = grid[0][0];
		for (int i(1); i < m; ++i)
			OPT[i][0] = OPT[i - 1][0] + grid[i][0];
		for (int i(1); i < n; ++i)
			OPT[0][i] = OPT[0][i - 1] + grid[0][i];
		for (int i(1); i < m; ++i) {
			for (int j(1); j < n; ++j)
				OPT[i][j] = min(OPT[i - 1][j], OPT[i][j - 1]) + grid[i][j];
		}
		return OPT[m - 1][n - 1];
	}
};
int main(void) {
	Solution solution;
	cout << "\nPassed All\n";
	getchar();
	return 0;
}