// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/
// https://discuss.leetcode.com/topic/14256/my-simple-and-clean-java-code-using-dfs-and-trie
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
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
		TrieNode *it = this->find(word);
		return it && it->isEnd;
	}
	bool startsWith(string word) {
		TrieNode *it = this->find(word);
		return it;
	}
	TrieNode *find(string word) {
		TrieNode *it = root;
		for (const auto &c : word) {
			if (!it->links[c - 'a']) return it->links[c - 'a'];
			it = it->links[c - 'a'];
		}
		return it;		
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
		vector<string> result;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board.front().size(); ++j) {
				string path;
				this->backTracking(i, j, path, result, board, maxLen, trie);
			}
		}
		return result;
	}
private:
	void backTracking(int i, int j, string& path, vector<string>& result, vector<vector<char>>& board, size_t maxLen, Trie &trie) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board.front().size() || board[i][j] == 'X' || path.size() > maxLen) return;
		path.push_back(board[i][j]);
		TrieNode *it = trie.find(path);
		if (!it) {
			path.pop_back();
			return;
		}
		if (it->isEnd) {
			result.push_back(path);
			it->isEnd = false;
		}
		char c = board[i][j];
		board[i][j] = 'X';
		this->backTracking(i - 1, j, path, result, board, maxLen, trie);
		this->backTracking(i + 1, j, path, result, board, maxLen, trie);
		this->backTracking(i, j - 1, path, result, board, maxLen, trie);
		this->backTracking(i, j + 1, path, result, board, maxLen, trie);
		board[i][j] = c;
		path.pop_back();
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