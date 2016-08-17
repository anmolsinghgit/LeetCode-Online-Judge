// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
// https://discuss.leetcode.com/topic/13248/very-concise-java-ac-solution
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid.front().size(); ++j) {
				if (grid[i][j] == '1') {
					this->DFS(i - 1, j, grid);
					this->DFS(i + 1, j, grid);
					this->DFS(i, j - 1, grid);
					this->DFS(i, j + 1, grid);
					++result;
				}
			}
		}
		return result;
	}
private:
	void DFS(int i, int j, vector<vector<char>>& grid) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid.front().size()) return;
		if (grid[i][j] == '0') return;
		grid[i][j] = '0';
		this->DFS(i - 1, j, grid);
		this->DFS(i + 1, j, grid);
		this->DFS(i, j - 1, grid);
		this->DFS(i, j + 1, grid);
		return;
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
	cout << solution.numIslands(grid) << "\tPassed\n";
	grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
	cout << solution.numIslands(grid) << "\tPassed\n";
	grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
	cout << solution.numIslands(grid) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}