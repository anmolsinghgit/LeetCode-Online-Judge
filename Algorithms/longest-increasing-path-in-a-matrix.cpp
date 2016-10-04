// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/35021/graph-theory-java-solution-o-v-2-no-dfs
class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		const int m = matrix.size();
		if (m == 0) return 0;
		const int n = matrix.front().size();
		if (n == 0) return 0;
		int number = m * n, result = 0;
		while (number) {
			unordered_set<int> zeroOutDegreeNodes;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (matrix[i][j] == INT_MIN) continue;
					bool top = (i == 0) || matrix[i][j] >= matrix[i - 1][j];
					bool bottom = (i + 1 == m) || matrix[i][j] >= matrix[i + 1][j];
					bool left = (j == 0) || matrix[i][j] >= matrix[i][j - 1];
					bool right = (j + 1 == n) || matrix[i][j] >= matrix[i][j + 1];
					if (top	 && bottom && left && right) zeroOutDegreeNodes.insert(j + n * i);
 				}
			}
			for (const auto &i : zeroOutDegreeNodes) {
				matrix[i / n][i % n] = INT_MIN;
				number--;
			}
			result++;
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/35021/graph-theory-java-solution-o-v-2-no-dfs
int main(void) {
	Solution solution;
	vector<vector<int>> matrix = { {9, 9, 4}, {6, 6, 8}, {2, 1, 1} };
	cout << solution.longestIncreasingPath(matrix) << "\tPassed\n";
	matrix = { {3, 4, 5}, {3, 2, 6}, {2, 2, 1} };
	cout << solution.longestIncreasingPath(matrix) << "\tPassed\n";
	matrix = { {9, 9, 4}, {6, 6, 8}, {2, 1, 1} };
	cout << solution.longestIncreasingPath(matrix) << "\tPassed\n";
	cout << "\nPassed All\n";	
	return 0;
}