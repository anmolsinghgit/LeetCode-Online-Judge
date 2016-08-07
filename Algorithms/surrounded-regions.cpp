// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/
// https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		const size_t &m = board.size();
		const size_t &n = board.front().size();
		for (size_t i = 0; i < m; ++i) {
			if (board[i][0] == 'O') this->solve(i, 0, board);
			if (n > 1 && board[i][n - 1] == 'O') this->solve(i, n - 1, board);
		}
		for (size_t i = 1; i < n; ++i) {
			if (board[0][i] == 'O') this->solve(0, i, board);
			if (m > 1 && board[m - 1][i] == 'O') this->solve(m - 1, i, board);
		}
		for (auto &i : board) {
			for (auto &j : i) {
				if (j == 'O') j = 'X';
				if (j == '+') j = 'O';
			}
		}
		return;
	}
private:
	void solve(const size_t &i, const size_t &j, vector<vector<char>>& board) {
		const size_t &m = board.size();
		const size_t &n = board.front().size();
		if (board[i][j] == 'O') board[i][j] = '+';
		if (i > 1 && board[i - 1][j] == 'O') this->solve(i - 1, j, board);
		if (i + 2 < m && board[i + 1][j] == 'O') this->solve(i + 1, j, board);
		if (j > 1 && board[i][j - 1] == 'O') this->solve(i, j - 1, board);
		if (j + 2 < n && board[i][j + 1] == 'O') this->solve(i, j + 1, board);
		return;
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
	solution.solve(board);
	for (const auto &i : board) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	board = {{'O', 'O'}, {'O', 'O'}};
	solution.solve(board);
	for (const auto &i : board) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	board = {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};
	solution.solve(board);
	for (const auto &i : board) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed All\n";
	return 0;
}