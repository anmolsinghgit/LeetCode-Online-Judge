// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		int m(obstacleGrid.size());
		int n(obstacleGrid.front().size());
		vector<vector<int>> OPT(m + 1, vector<int>(n + 1, 0));
		if (obstacleGrid[m - 1][n - 1] == 0)
			OPT[m - 1][n - 1] = 1;
		for (int i(m - 1); i >= 0; --i) {
			for (int j(n - 1); j >= 0; --j) {
				if (i + 1 == m && j + 1 == n)
					continue;
				else {
					if (obstacleGrid[i][j] == 0)
						OPT[i][j] = OPT[i + 1][j] + OPT[i][j + 1];
				}
			}
		}
		return OPT[0][0];
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> A;
	A.push_back(vector<int>({0,0,0}));
	A.push_back(vector<int>({0,1,0}));
	A.push_back(vector<int>({0,0,0}));
	int b(2);
	if (b ^ solution.uniquePathsWithObstacles(A)) {
		cout << "\nError\n";
		getchar();
		return 0;
	}
	else {
		cout << "\nPassed\n";
		getchar();
		return 0;
	}
}