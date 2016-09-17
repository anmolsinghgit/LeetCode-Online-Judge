// 286. Walls and Gates
// https://leetcode.com/problems/walls-and-gates/
// https://leetcode.com/articles/walls-and-gates/#approach-2-breadth-first-search-accepted
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (int i = 0; i < (int)rooms.size(); ++i) {
			for (int j = 0; j < (int)rooms.front().size(); ++j) {
				if (rooms[i][j] == 0) {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<int, int> point = q.front();
						for (const auto &i : directions) {
							int x = point.first + i.first, y = point.second + i.second;
							if (x < 0 || x >= (int)rooms.size() || y < 0 || y >= (int)rooms.front().size()) continue;
							if (rooms[x][y] > 0 && rooms[x][y] > rooms[point.first][point.second] + 1) {
								rooms[x][y] = rooms[point.first][point.second] + 1;
								q.push(make_pair(x, y));
							}
						}
						q.pop();
					}
				}
			}
		}
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> rooms = {{INT_MAX, -1, 0, INT_MAX}, {INT_MAX, INT_MAX, INT_MAX, -1}, {INT_MAX, -1, INT_MAX, -1}, {0, -1, INT_MAX, INT_MAX}};
	for (const auto &i : rooms) {
		for (const auto &j : i)
			cout << j << '\t';
		cout << '\n';		
	}
	solution.wallsAndGates(rooms);
	cout << '\n';
	for (const auto &i : rooms) {
		for (const auto &j : i)
			cout << j << '\t';
		cout << '\n';		
	}
	return 0;
}