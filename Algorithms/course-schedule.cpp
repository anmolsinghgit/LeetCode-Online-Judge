// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/
// https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions/2
// https://discuss.leetcode.com/topic/13854/easy-bfs-topological-sort-java
#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
using namespace std;
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = this->generateGraph(numCourses, prerequisites);
		vector<int> indegrees = this->generateIndegrees(numCourses, graph);
		for (int i = 0; i < numCourses; ++i) {
			int j;
			for (j = 0; indegrees[j] && j < numCourses; ++j) ;
			if (j == numCourses) return false;
			indegrees[j] = numeric_limits<int>::min();
			for (const auto &k : graph[j]) --indegrees[k];
		}
		return true;
	}
private:
	vector<unordered_set<int>> generateGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> result(numCourses);
		for (const auto &i : prerequisites) result[i.second].insert(i.first);
		return result;
	}
	vector<int> generateIndegrees(int numCourses, vector<unordered_set<int>>& graph) {
		vector<int> result(numCourses, 0);
		for (const auto &i : graph)
			for (const auto &j : i)
				++result[j];
		return result;
	}
};
int main(void) {
	Solution solution;
	int numCourses = 2;
	vector<pair<int, int>> prerequisites = {{1, 0}};
	cout << boolalpha << solution.canFinish(numCourses, prerequisites) << "\tPassed\n";
	numCourses = 2;
	prerequisites = {{1, 0}, {0, 1}};
	cout << boolalpha << solution.canFinish(numCourses, prerequisites) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
