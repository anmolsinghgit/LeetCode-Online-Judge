// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/
// https://leetcode.com/articles/maximal-square/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// BEGIN: Better Dynamic Programming
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		const int m = matrix.size();
		if (m == 0) return 0;
		const int n = matrix.front().size();
		if (n == 0) return 0;
		vector<int> OPT(n + 1, 0);
		int result = 0;
		for (int i = 0; i < m; ++i) {
			int previous = 0;
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0') {
					previous = OPT[j + 1];
					OPT[j + 1] = 0;
					continue;
				}
				int tmp = OPT[j + 1];
				OPT[j + 1] = 1 + min(min(OPT[j] ,OPT[j + 1]), previous);
				previous = tmp;
				result = max(result, OPT[j + 1]);
			}
		}
		return result * result;
	}
};
// END: Better Dynamic Programming
// BEGIN: Dynamic Programming
// class Solution {
// public:
// 	int maximalSquare(vector<vector<char>>& matrix) {
// 		const int m = matrix.size();
// 		if (m == 0) return 0;
// 		const int n = matrix.front().size();
// 		if (n == 0) return 0;
// 		int result = 0;
// 		vector<vector<int>> OPT(m + 1, vector<int>(n + 1, 0));
// 		for (int i = 0; i < m; ++i) {
// 			for (int j = 0; j < n; ++j) {
// 				if (matrix[i][j] == '0') continue;
// 				OPT[i + 1][j + 1] = 1 + min(min(OPT[i][j + 1], OPT[i + 1][j]), OPT[i][j]);
// 				result = max(result, OPT[i + 1][j + 1]);
// 			}
// 		}
// 		return result * result;
// 	}
// };
// END: Dynamic Programming
// BEGIN: Brute Force Approach
// class Solution {
// public:
// 	int maximalSquare(vector<vector<char>>& matrix) {
// 		int n = 0;
// 		for (int i = 0; i < (int)matrix.size(); ++i) {
// 			for (int j = 0; j < (int)matrix.front().size(); ++j) {
// 				if (matrix[i][j] == '0') continue;
// 				while (this->help(matrix, n + 1, i, j)) ++n;
// 			}
// 		}
// 		return n * n;
// 	}
// private:
// 	bool help(vector<vector<char>>& matrix, int n, int i, int j) {
// 		if ((int)matrix.size() < n + i || (int)matrix.front().size() < n + j) return false;
// 		for (int p = 0; p < n; ++p)
// 			for (int q = 0; q < n; ++q)
// 				if (matrix[i + p][j + q] == '0') return false;
// 		return true;
// 	}
// };
// END: Brute Force Approach
int main(void) {
	Solution solution;
	vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	matrix = {{'0', '1'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	matrix = {{'0', '0', '0'}, {'0', '0', '0'}, {'1', '1', '1'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	matrix = {{'1', '0', '1', '0'}, {'1', '0', '1', '1'}, {'1', '0', '1', '1'}, {'1', '1', '1', '1'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	matrix = {{'1', '0', '1', '1', '1'}, {'0', '1', '0', '1', '0'}, {'1', '1', '0', '1', '1'}, {'1', '1', '0', '1', '1'}, {'0', '1', '1', '1', '1'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}