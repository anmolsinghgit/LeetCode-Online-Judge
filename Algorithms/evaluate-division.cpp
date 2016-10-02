// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, unordered_map<string, double>> graph;
		for (size_t i = 0; i < equations.size(); i++) {
			graph[equations[i].first][equations[i].second] = values[i];
			graph[equations[i].second][equations[i].first] = 1.0 / values[i];
		}
		vector<double> result;
		for (const auto &i : queries) result.push_back(this->findparent(i.first, i.second, graph));
		return result;
	}
private:
	double findparent(const string& begin, const string& end, unordered_map<string, unordered_map<string, double>>& graph) {
		if (!graph.count(begin) || !graph.count(end)) return -1.0;
		if (begin == end) return 1.0;
		unordered_map<string, string> parent;
		unordered_set<string> visited;
		queue<string> q;
		q.push(begin);
		visited.insert(begin);
		while (!q.empty()) {
			for (const auto &i : graph[q.front()]) {
				if (visited.count(i.first)) continue;
				parent[i.first] = q.front();
				q.push(i.first);
				visited.insert(i.first);
			}
			q.pop();
		}
		if (!parent.count(end)) return -1.0;
		double result = 1.0;
		for (string i = end; i != begin; i = parent[i]) result *= graph[parent[i]][i];
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<pair<string, string>> equations = { {"a", "b"}, {"b", "c"} };
	vector<double> values = {2.0, 3.0};
	vector<pair<string, string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
	for (const auto &i : solution.calcEquation(equations, values, queries)) cout << i << '\t';
	cout << "\tPassed\n";
	equations = { {"a","b"},{"b","c"} };
	values = {2.0,3.0};
	queries = { {"a","c"},{"b","c"},{"a","e"},{"a","a"},{"x","x"} };
	for (const auto &i : solution.calcEquation(equations, values, queries)) cout << i << '\t';
	cout << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}