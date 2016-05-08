// 30. Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// https://www.youtube.com/watch?v=Tua6hom2rZs
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(const string& s, const vector<string>& words) {
		vector<int> result;
		int wordLength = words.front().size();
		this->setTotalWordsLength(words);
		int sLength = s.size();
		if (sLength < this->totalWordsLength)
			return result;
		this->setWordsMap(words);
		/*
		s =  b  a  r  f  o  o  t  h  e  f  o  o  b  a  r  m  a  n
		i = 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17
		                                         b  a  r  f  o  o
		*/
		for (int i = 0; i <= sLength - this->totalWordsLength; ++i) {
			string subStr = s.substr(i , this->totalWordsLength);
			if (this->match(subStr, wordLength)) {
				result.push_back(i);
			}
		}
		return result;
	}
private:
	int totalWordsLength;
private:
	void setTotalWordsLength(const vector<string>& words) {
		this->totalWordsLength = words.front().size() * words.size();
	}
private:
	unordered_map<string, int> wordsMap;
private:
	void setWordsMap(const vector<string>& words) {
		for(const auto& i : words)
			++this->wordsMap[i];
	}
private:
	bool match(const string& s, const int& wordLength) {
		/*
		s =  b  a  r  f  o  o  t  h  e  f  o  o  b  a  r  m  a  n
		i = 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17
		*/
		if (s.size() != this->totalWordsLength)
			return false;
		unordered_map<string, int> tempWordsMap;
		for (int i = 0; i < this->totalWordsLength; i += wordLength) {
			string subStr = s.substr(i, wordLength);
			++tempWordsMap[subStr];
		}
		bool result = false;
		for (const auto& i : this->wordsMap) {
			if (!tempWordsMap.count(i.first)) {
				result = false;
				break;
			}
			else {
				if (tempWordsMap[i.first] == i.second) {
					result = true;
				}
				else {
					result = false;
					break;
				}
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	string s = "barfoothefoobarman";
	vector<string> words = { "foo", "bar" };
	for (const auto& i : solution.findSubstring(s, words)) {
		cout << i << '\t';
	}
	cout << "\nPassed\n";
	getchar();
	return 0;
}
