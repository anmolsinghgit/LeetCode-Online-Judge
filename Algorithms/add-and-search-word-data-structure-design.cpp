// 211. Add and Search Word - Data structure design
// https://leetcode.com/problems/add-and-search-word-data-structure-design/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class TrieNode {
public:
	TrieNode(): isEnd(false) {
		memset(links, 0, sizeof(links));
	}
	TrieNode *links[26];
	bool isEnd;
};
class WordDictionary {
public:
	WordDictionary(): root(new TrieNode()) {}
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode *it = this->root;
		for (size_t i = 0; i < word.size(); ++i) {
			if (!it->links[word[i] - 'a']) it->links[word[i] - 'a'] = new TrieNode();
			it = it->links[word[i] - 'a'];
		}
		it->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return this->search(0, word, this->root);
	}
private:
	TrieNode *root;
	bool search(size_t start, string word, TrieNode *current) {
		if (!current) return false;
		if (word[start] == '.') {
			if (start + 1 == word.size()) {
				for (int i = 0; i < 26; ++i) if (current->links[i] && current->links[i]->isEnd) return true;
				return false;
			}
			for (int i = 0; i < 26; ++i) if (this->search(start + 1, word, current->links[i])) return true;
			return false;
		}
		if (start + 1 == word.size()) return current->links[word[start] - 'a'] && current->links[word[start] - 'a']->isEnd;
		return current->links[word[start] - 'a'] && this->search(start + 1, word, current->links[word[start] - 'a']);
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(void) {
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	cout << boolalpha << wordDictionary.search("pad") << "\tPassed\n";
	cout << boolalpha << wordDictionary.search("bad") << "\tPassed\n";
	cout << boolalpha << wordDictionary.search(".ad") << "\tPassed\n";
	cout << boolalpha << wordDictionary.search("b..") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}