// 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/
// https://discuss.leetcode.com/topic/17276/20-lines-c-bfs-dfs-solutions
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = this->generateGraph(numCourses, prerequisites);
		vector<int> indegrees = this->generateIndegrees(numCourses, graph);
		deque<int> zeros;
		for (int i = 0; i < numCourses; ++i) if (!indegrees[i]) zeros.push_back(i);
		vector<int> result;
		for (int i = 0; i < numCourses; ++i) {
			if (zeros.empty()) return {};
			int zero = zeros.front();
			zeros.pop_front();
			result.push_back(zero);
			for (const auto &j : graph[zero]) if (!--indegrees[j]) zeros.push_back(j);
		}
		return result;
	}
private:
	vector<unordered_set<int>> generateGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> result(numCourses);
		for (const auto &i : prerequisites) result[i.second].insert(i.first);
		return result;
	}
	vector<int> generateIndegrees(int numCourses, vector<unordered_set<int>>& graph) {
		vector<int> result(numCourses, 0);
		for (const auto &i : graph) for (const auto &j : i) ++result[j];
		return result;
	}
};
int main(void) {
	Solution solution;
	int numCourses = 2;
	vector<pair<int, int>> prerequisites = {{1, 0}};
	for (const auto &i : solution.findOrder(numCourses, prerequisites)) cout << i << '\t';
	cout << "\tPassed\n";
	numCourses = 4;
	prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
	for (const auto &i : solution.findOrder(numCourses, prerequisites)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}