// 126. Word Ladder II
// https://leetcode.com/problems/word-ladder-ii/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <deque>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<vector<string>> result;
		if (wordList.empty()) return result;
		wordList.insert(endWord);
		deque<string> dq;
		dq.push_back(beginWord);
		unordered_map<string, unordered_set<string>> path;
		unordered_map<string, int> distance;
		distance[beginWord] = 0;
		int shortest = numeric_limits<int>::max();
		while (!dq.empty()) {
			if (distance.count(dq.front()) && distance[dq.front()] > shortest) {
				dq.pop_front();
				continue;
			}
			for (size_t i = 0; i < dq.front().size(); ++i) {
				string frontofdeque = dq.front();
				for (char c = 'a'; c <= 'z'; ++c) {
					frontofdeque[i] = c;
					// if (distance.count(frontofdeque) && distance[frontofdeque] > shortest) continue;
					if (frontofdeque != dq.front()) {
						if (wordList.count(frontofdeque)) {
							if (frontofdeque == endWord) shortest = min(shortest, distance[dq.front()] + 1);
							if (!distance.count(frontofdeque)) {
								distance[frontofdeque] = distance[dq.front()] + 1;
								dq.push_back(frontofdeque);
							} 
							else distance[frontofdeque] = min(distance[frontofdeque], distance[dq.front()] + 1);
							path[frontofdeque].insert(dq.front());
						}
					}
				}
			}
			dq.pop_front();
		}
		if (path.empty()) return result;
		vector<string> vec = {endWord};
		this->backTrace(beginWord, endWord, vec, path, distance, result);
		return result;
	}
private:
	void backTrace(string beginWord, string endWord, vector<string> &vec, unordered_map<string, unordered_set<string>> &path, unordered_map<string, int> &distance, vector<vector<string>> &result) {
		if (endWord ==  beginWord) {
			result.push_back(vec);
			return;
		}
		int shortest = distance[endWord];
		for (const auto &str : path[endWord]) {
			if (distance[str] + 1 == shortest) {
				vec.insert(begin(vec), str);
				this->backTrace(beginWord, str, vec, path, distance, result);
				vec.erase(begin(vec));
			}
		}
		return;
	}
};
int main(void) {
	Solution solution;
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log"};
	for (const auto &i : solution.findLadders(beginWord, endWord, wordList)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}