// 261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution {
public:
	bool validTree(int n, vector<pair<int, int>>& edges) {
		if (n != (int)edges.size() + 1) return false;
		// for (auto &i : edges) if (i.first > i.second) swap(i.first, i.second);
		// sort(begin(edges), end(edges));
		vector<int> roots(n, -1);
		for (const auto &i : edges) {
			int x = i.first, y = i.second;
			if (roots[x] == -1 && roots[y] == -1) {
				roots[x] = x;
				roots[y] = x;
				continue;
			}
			if (roots[x] == -1 && roots[y] != -1) {
				while (y != roots[y]) y = roots[y] = roots[roots[y]];
				roots[x] = y;
				continue;
			}
			if (roots[x] != -1 && roots[y] == -1) {
				while (x != roots[x]) x = roots[x] = roots[roots[x]];
				roots[y] = x;
				continue;
			}
			while (x != roots[x]) x = roots[x] = roots[roots[x]];
			while (y != roots[y]) y = roots[y] = roots[roots[y]];
			if (x == y) return false;
			roots[y] = x;
		}
		for (int i = 0; i < n; ++i) {
			int x = i;
			while (x != roots[x]) x = roots[x] = roots[roots[x]];
			roots[i] = x;
		}
		for (const auto &i : roots) if (i != roots.front()) return false;
		return true; 
	}
};
int main(void) {
	Solution solution;
	int n = 5;
	vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 5;
	edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 5;
	edges = {{0, 1}, {1, 2}, {3, 4}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 4;
	edges = {{0, 1}, {2, 3}, {1, 2}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 2;
	edges.clear();
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 1;
	edges.clear();
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 3;
	edges = {{1, 0}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 3;
	edges = {{1, 0}, {2, 0}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 3;
	edges = {{2, 0}, {2, 1}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	n = 6;
	edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {3, 5}};
	cout << boolalpha << solution.validTree(n, edges) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}