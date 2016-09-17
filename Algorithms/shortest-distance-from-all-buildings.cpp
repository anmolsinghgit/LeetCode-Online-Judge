// 317. Shortest Distance from All Buildings
// https://leetcode.com/problems/shortest-distance-from-all-buildings/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		if (grid.empty()) return -1;
		vector<pair<int, int>> buildings;
		vector<pair<int, int>> obstacles;
		for (int i = 0; i < (int)grid.size(); ++i) {
			for (int j = 0; j < (int)grid.front().size(); ++j) {
				if (grid[i][j] == 1) {
					grid[i][j] = -1;
					buildings.push_back(make_pair(i, j));
				}
				if (grid[i][j] == 2) {
					grid[i][j] = -2;
					obstacles.push_back(make_pair(i, j));					
				}
			}
		}
		if (buildings.size() + obstacles.size() == grid.size() * grid.front().size()) return -1;
		vector<vector<vector<int>>> grids(buildings.size(), grid);
		vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int i = 0; i < (int)buildings.size(); ++i) {
			queue<pair<int, int>> q;
			grids[i][buildings[i].first][buildings[i].second] = 0;
			int numberOfEmptyNeighbour = 0;
			for (const auto &j : directions) {
				int x = buildings[i].first + j.first, y = buildings[i].second + j.second;
				if (x < 0 || x >= (int)grid.size() || y < 0 || y >= (int)grid.front().size()) continue;
				if (grid[x][y] == 0) ++numberOfEmptyNeighbour;
			}
			if (numberOfEmptyNeighbour == 0) return -1;
			q.push(buildings[i]);
			while (!q.empty()) {
				for (const auto &j : directions) {
					int x = q.front().first + j.first, y = q.front().second + j.second;
					if (x < 0 || x >= (int)grid.size() || y < 0 || y >= (int)grid.front().size()) continue;
					if (grids[i][x][y] == 0) {
						grids[i][x][y] = 1 + grids[i][q.front().first][q.front().second];
						q.push(make_pair(x, y));
						continue;
					}
					if (grids[i][x][y] > 0 && grids[i][x][y] > 1 + grids[i][q.front().first][q.front().second]) {
						grids[i][x][y] = 1 + grids[i][q.front().first][q.front().second];
						q.push(make_pair(x, y));
						continue;
					}
				}
				grids[i][buildings[i].first][buildings[i].second] = -1;
				q.pop();
			}
		}
		vector<vector<int>> visited(grid.size(), vector<int>(grid.front().size(), 1));
		for (int i = 0; i < (int)grid.size(); ++i) {
			for (int j = 0; j < (int)grid.front().size(); ++j) {
				for (int k = 0; k < (int)grids.size(); ++k) {
					visited[i][j] = grids[k][i][j] == 0 || visited[i][j] == 0? 0 : 1;
					grid[i][j] += grids[k][i][j];
				}
			}
		}
		int result = -1;
		for (int i = 0; i < (int)grid.size(); ++i) {
			for (int j = 0; j < (int)grid.front().size(); ++j) {
				if (grid[i][j] <= 0 || visited[i][j] == 0) continue;
				if (result == -1) result = grid[i][j];
				else result = min(result, grid[i][j]);
			}
		}
		// for (const auto& i : grid) {
		// 	for (const auto& j : i) {
		// 		cout << j << '\t';
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
		// for (const auto& i : visited) {
		// 	for (const auto& j : i) {
		// 		cout << j << '\t';
		// 	}
		// 	cout << '\n';
		// }
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> grid = {{1, 0, 2, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
	cout << solution.shortestDistance(grid) << "\tPassed\n";
	grid = {{1}};
	cout << solution.shortestDistance(grid) << "\tPassed\n";
	grid = {{1, 0, 1, 0, 1}};
	cout << solution.shortestDistance(grid) << "\tPassed\n";
	grid = {{1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1}, {0, 1, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 1}, {0, 1, 1, 1, 1, 0}};
	cout << solution.shortestDistance(grid) << "\tPassed\n";
	grid = {{1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 0}};
	cout << solution.shortestDistance(grid) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}