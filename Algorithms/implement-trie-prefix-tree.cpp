// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/
// http://www.cnblogs.com/grandyang/p/4491665.html
// https://leetcode.com/articles/implement-trie-prefix-tree/
// http://www.cplusplus.com/reference/cstring/memset/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode(): isEnd(false) {
		memset(links, NULL, sizeof(links));
	}
	TrieNode *links[26];
	bool isEnd;
};

class Trie {
public:
	Trie(): root(new TrieNode()) {}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *it = this->root;
		for (const auto &i : word) {
			if (!it->links[i - 'a']) it->links[i - 'a'] = new TrieNode();
			it = it->links[i - 'a'];
		}
		it->isEnd = true;
		return;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *it = this->root;
		for (const auto &i : word) {
			if (!it->links[i - 'a']) return false;
			it = it->links[i - 'a'];
		}
		return it->isEnd;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *it = this->root;
		for (const auto &i : prefix) {
			if (!it->links[i - 'a']) return false;
			it = it->links[i - 'a'];
		}
		return true;		
	}

private:
	TrieNode *root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(void) {
	Trie trie;
	trie.insert("somestring");
	cout << boolalpha << trie.search("key");
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}