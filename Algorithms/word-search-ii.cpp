// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iterator>
using namespace std;
class TrieNode {
public:
	TrieNode(): isEnd(false) {
		memset(links, 0, sizeof(links));
	}
	TrieNode *links[26];
	bool isEnd;
};
class Trie {
public:
	Trie(): root(new TrieNode()) {}
	void insert(string word) {
		TrieNode *it = this->root;
		for (const auto &c : word) {
			if (!it->links[c - 'a']) it->links[c - 'a'] = new TrieNode();
			it = it->links[c - 'a'];
		}
		it->isEnd = true;
	}
	bool search(string word) {
		TrieNode *it = root;
		for (const auto &c : word) {
			if (!it->links[c - 'a']) return false;
			it = it->links[c - 'a'];
		}
		return it && it->isEnd;
	}
	bool startsWith(string word) {
		TrieNode *it = root;
		for (const auto &c : word) {
			if (!it->links[c - 'a']) return false;
			it = it->links[c - 'a'];
		}
		return true;
	}
private:
	TrieNode *root;
};
class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie trie;
		size_t maxLen = 0;
		for (const auto &s : words) {
			trie.insert(s);
			maxLen = max(maxLen, s.size());
		}
		unordered_set<string> result;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board.front().size(); ++j) {
				string path;
				path.push_back(board[i][j]);
				vector<vector<bool>> visited(board.size(), vector<bool>(board.front().size(), false));
				visited[i][j] = true;
				if (!trie.startsWith(path)) continue;
				if (trie.search(path)) result.insert(path);
				this->backTracking(i, j, path, visited, result, board, maxLen, trie);
			}
		}
		return vector<string>(begin(result), end(result));
	}
private:
	void backTracking(int i, int j, string path, vector<vector<bool>>& visited, unordered_set<string>& result, vector<vector<char>>& board, size_t maxLen, Trie &trie) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board.front().size() || !visited[i][j] || path.size() > maxLen) return;
		if (i >= 1 && !visited[i - 1][j]) {
			path.push_back(board[i - 1][j]);
			if (trie.startsWith(path)) {
				if (trie.search(path)) result.insert(path);
				visited[i - 1][j] = true;
				this->backTracking(i - 1, j, path, visited, result, board, maxLen, trie);
				visited[i - 1][j] = false;
			}
			path.pop_back();
		}
		if (i + 1 < board.size() && !visited[i + 1][j]) {
			path.push_back(board[i + 1][j]);
			if (trie.startsWith(path)) {
				if (trie.search(path)) result.insert(path);
				visited[i + 1][j] = true;
				this->backTracking(i + 1, j, path, visited, result, board, maxLen, trie);
				visited[i + 1][j] = false;
			}
			path.pop_back();
		}
		if (j >= 1 && !visited[i][j - 1]) {
			path.push_back(board[i][j - 1]);
			if (trie.startsWith(path)) {
				if (trie.search(path)) result.insert(path);
				visited[i][j - 1] = true;
				this->backTracking(i, j - 1, path, visited, result, board, maxLen, trie);
				visited[i][j - 1] = false;
			}
			path.pop_back();
		}
		if (j + 1 < board.front().size() && !visited[i][j + 1]) {
			path.push_back(board[i][j + 1]);
			if (trie.startsWith(path)) {
				if (trie.search(path)) result.insert(path);
				visited[i][j + 1] = true;
				this->backTracking(i, j + 1, path, visited, result, board, maxLen, trie);
				visited[i][j + 1] = false;
			}
			path.pop_back();
		}
		return;
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> board = {
									{'o','a','a','n'},
									{'e','t','a','e'},
									{'i','h','k','r'},
									{'i','f','l','v'}
								};
	vector<string> words = {"oath","pea","eat","rain"};
	for (const auto & i : solution.findWords(board, words)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed\n";
	return 0;
}