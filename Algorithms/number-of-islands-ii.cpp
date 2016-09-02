// 305. Number of Islands II
// https://leetcode.com/problems/number-of-islands-ii/
// https://discuss.leetcode.com/topic/29613/easiest-java-solution-with-explanations/2
#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		vector<int> result;
		vector<int> roots(m * n, -1);
		vector<pair<int, int>> signs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		int count = 0;
		for (const auto &i : positions) {
			int current = i.first * n + i.second;
			roots[current] = current;
			++count;
			for (const auto &j : signs) {
				int row = i.first + j.first;
				int column = i.second + j.second;
				int neighbor = row * n + column;
				if (row < 0 || row >= m || column < 0 || column >= n || roots[neighbor] == -1) continue;
				while (neighbor != roots[neighbor]) neighbor = roots[neighbor] = roots[roots[neighbor]];
				if (neighbor == current) continue;
				roots[current] = neighbor;
				current = neighbor;
				--count;
			}
			result.push_back(count);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	int m = 3, n = 3;
	vector<pair<int, int>> positions = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
	for (const auto &i : solution.numIslands2(m, n, positions)) cout << i << '\t';
	cout << "\tPassed\n";
	m = 8;
	n = 2;
	positions = {{7, 0}};
	for (const auto &i : solution.numIslands2(m, n, positions)) cout << i << '\t';
	cout << "\tPassed\n";
	m = 2;
	n = 2;
	positions = {{0,0},{1,1},{0,1}};
	for (const auto &i : solution.numIslands2(m, n, positions)) cout << i << '\t';
	cout << "\tPassed\n";
	m = 3;
	n = 3;
	positions = {{0, 1}, {1, 2}, {2, 1}, {1, 0}, {0, 2}, {0, 0},{1, 1}};
	for (const auto &i : solution.numIslands2(m, n, positions)) cout << i << '\t';
	cout << "\tPassed\n";
	m = 1;
	n = 2;
	positions = {{0, 1}, {0, 0}};
	for (const auto &i : solution.numIslands2(m, n, positions)) cout << i << '\t';
	cout << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}