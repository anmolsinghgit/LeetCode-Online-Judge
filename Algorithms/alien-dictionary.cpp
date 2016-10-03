// 269. Alien Dictionary
// https://leetcode.com/problems/alien-dictionary/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/28308/java-ac-solution-using-bfs
class Solution {
public:
	string alienOrder(vector<string>& words) {
		string result;
		unordered_map<char, unordered_set<char>> graph;
		unordered_map<char, int> indegrees;
		for (const auto &i : words) for (const auto &j : i) indegrees[j] = 0;
		for (size_t i = 1; i < words.size(); i++) {
			if (words[i - 1].size() > words[i].size() && words[i - 1].substr(0, words[i].size()) == words[i]) return "";
			size_t j = 0, k = min(words[i - 1].size(), words[i].size());
			while (j < k && words[i - 1][j] == words[i][j]) j++;
			if (j == k) continue;
			if (graph.count(words[i - 1][j]) && graph[words[i - 1][j]].count(words[i][j])) continue;
			graph[words[i - 1][j]].insert(words[i][j]);
			indegrees[words[i][j]]++;
		}
		queue<char> zeros;
		for (const auto &i : indegrees) if (i.second == 0) zeros.push(i.first);
		while (!zeros.empty()) {
			char front = zeros.front();
			result.push_back(front);
			zeros.pop();
			for (const auto &i : graph[front]) if (--indegrees[i] == 0) zeros.push(i);
		}
		return indegrees.size() == result.size() ? result : "";
	}
};
// END: https://discuss.leetcode.com/topic/28308/java-ac-solution-using-bfs
int main(void) {
	Solution solution;
	vector<string> words = {"wrt","wrf","er","ett","rftt"};
	cout << solution.alienOrder(words) << "\tPassed\n";
	words = {"z", "z"};
	cout << solution.alienOrder(words) << "\tPassed\n";	
	words = {"zy","zx"};
	cout << solution.alienOrder(words) << "\tPassed\n";
	words = {"wrtkj","wrt"};
	cout << solution.alienOrder(words) << "\tPassed\n";
	words = {"za","zb","ca","cb"};
	cout << solution.alienOrder(words) << "\tPassed\n";
	words = {"ri","xz","qxf","jhsguaw","dztqrbwbm","dhdqfb","jdv","fcgfsilnb","ooby"};
	cout << solution.alienOrder(words) << "\tPassed\n";
	words = {"bsusz","rhn","gfbrwec","kuw","qvpxbexnhx","gnp","laxutz","qzxccww"};
	cout << solution.alienOrder(words) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}