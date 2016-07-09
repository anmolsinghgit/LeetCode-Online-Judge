// 51. N-Queens
// https://leetcode.com/problems/n-queens/
// https://discuss.leetcode.com/topic/13617/accepted-4ms-c-solution-use-backtracking-and-bitmask-easy-understand
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(const int& n) {
		vector<vector<string>> result;
		vector<string> solution(n, string(n, '.'));
		this->solveNQueens(result, solution, 0, n);
		return result;
	}
private:
	void solveNQueens(vector<vector<string>>& result, vector<string>& solution, const int& row, const int& n) {
		if (row == n) {
			result.push_back(solution);
			return;
		}
		else {
			for (int i(0); i < n; ++i) {
				if (this->isValid(row, i, solution, n)) {
					solution[row][i] = 'Q';
					this->solveNQueens(result, solution, row + 1, n);
					solution[row][i] = '.';
				}
			}
			return;
		}
	}
private:
	bool isValid(const int& row, const int& column, const vector<string>& solution, const int& n) {
		for (int i(0); i < row; ++i) {
			if (solution[i][column] == 'Q')
				return false;
		}
		for (int i(row - 1), j(column - 1); i >= 0 && j >= 0; --i, --j) {
			if (solution[i][j] == 'Q')
				return false;
		}
		for (int i(row - 1), j(column + 1); i >= 0 && j <= n - 1; --i, ++j) {
			if (solution[i][j] == 'Q')
				return false;
		}
		return true;
	}
};
int main(void) {
	Solution solution;
	int n(8);
	for (const auto& i : solution.solveNQueens(n)) {
		for (const auto& j : i) {
			for (const auto& k : j)
				cout << k;
			cout << '\n';
		}
		cout << '\n';
	}
	getchar();
	return 0;
}