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
		memset(links, 0, sizeof(links));
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
		for (const auto &c : word) {
			if (!it->links[c - 'a']) it->links[c - 'a'] = new TrieNode();
			it = it->links[c - 'a'];
		}
		it->isEnd = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *it = this->find(word);
		return it && it->isEnd;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
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