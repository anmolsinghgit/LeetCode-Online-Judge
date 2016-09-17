// 286. Walls and Gates
// https://leetcode.com/problems/walls-and-gates/
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
		for (size_t i = 0; i < rooms.size(); ++i) {
			for (size_t j = 0; j < rooms.front().size(); ++j) {
				if (rooms[i][j] == 0) {
					queue<pair<size_t, size_t>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						pair<size_t, size_t> point = q.front();
						if (point.first >= 1 && rooms[point.first - 1][point.second] > 0 && rooms[point.first - 1][point.second] > rooms[point.first][point.second] + 1) {
							rooms[point.first - 1][point.second] = rooms[point.first][point.second] + 1;
							q.push(make_pair(point.first - 1, point.second));
						}
						if (point.first + 1 < rooms.size() && rooms[point.first + 1][point.second] > 0 && rooms[point.first + 1][point.second] > rooms[point.first][point.second] + 1) {
							rooms[point.first + 1][point.second] = rooms[point.first][point.second] + 1;
							q.push(make_pair(point.first + 1, point.second));							
						}
						if (point.second >= 1 && rooms[point.first][point.second - 1] > 0 && rooms[point.first][point.second - 1] > rooms[point.first][point.second] + 1) {
							rooms[point.first][point.second - 1] = rooms[point.first][point.second] + 1;
							q.push(make_pair(point.first, point.second - 1));
						}
						if (point.second + 1 < rooms.front().size() && rooms[point.first][point.second + 1] > 0 && rooms[point.first][point.second + 1] > rooms[point.first][point.second] + 1) {
							rooms[point.first][point.second + 1] = rooms[point.first][point.second] + 1;
							q.push(make_pair(point.first, point.second + 1));
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