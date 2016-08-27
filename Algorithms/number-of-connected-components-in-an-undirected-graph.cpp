// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// https://discuss.leetcode.com/topic/32752/easiest-2ms-java-solution
// https://discuss.leetcode.com/topic/29613/easiest-java-solution-with-explanations
// https://discuss.leetcode.com/topic/32677/short-union-find-in-python-ruby-c
// http://www.cplusplus.com/reference/numeric/iota/
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;
class Solution {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		vector<int> parent(n);
		iota(begin(parent), end(parent), 0);
		for (const auto &i : edges) {
			int x = i.first;
			int y = i.second;
			while (parent[x] != x) x = parent[x] = parent[parent[x]];
			while (parent[y] != y) y = parent[y] = parent[parent[y]];
			parent[x] = y;
			n -= x != y;
		}
		return n;
	}
};
int main(void) {
	Solution solution;
	int n = 5;
	vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}};
	cout << solution.countComponents(n, edges) << "\tPassed\n";
	n = 5;
	edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
	cout << solution.countComponents(n, edges) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}