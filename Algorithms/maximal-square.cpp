// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int n = 0;
		for (int i = 0; i < (int)matrix.size(); ++i) {
			for (int j = 0; j < (int)matrix.front().size(); ++j) {
				if (matrix[i][j] == '0') continue;
				while (this->help(matrix, n + 1, i, j)) ++n;
			}
		}
		return n * n;
	}
private:
	bool help(vector<vector<char>>& matrix, int n, int i, int j) {
		if ((int)matrix.size() < n + i || (int)matrix.front().size() < n + j) return false;
		for (int p = 0; p < n; ++p)
			for (int q = 0; q < n; ++q)
				if (matrix[i + p][j + q] == '0') return false;
		return true;
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	matrix = {{'0', '1'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	matrix = {{'0', '0', '0'}, {'0', '0', '0'}, {'1', '1', '1'}};
	cout << solution.maximalSquare(matrix) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}