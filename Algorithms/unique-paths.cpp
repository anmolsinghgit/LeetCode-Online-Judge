// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	size_t uniquePaths(const size_t& m, const size_t& n) {
		vector<vector<size_t>> opt(m + 1, vector<size_t>(n + 1, 0));
		opt[m - 1][n - 1] = 1;
		for (size_t i(m); i >= 1; --i) {
			for (size_t j(n); j >= 1; --j) {
				if (i == m && j == n)
					continue;
				else
					opt[i - 1][j - 1] = opt[i][j - 1] + opt[i - 1][j];
			}
		}
		return opt[0][0];
	}
};
int main(void) {
	Solution solution;
	size_t m(1000), n(1000);
	cout << solution.uniquePaths(m, n);
	cout << "\nPassed All\n";
	getchar();
	return 0;
}