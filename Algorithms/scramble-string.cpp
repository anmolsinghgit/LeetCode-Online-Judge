// 87. Scramble String
// https://leetcode.com/problems/scramble-string/
// https://discuss.leetcode.com/topic/14337/share-my-4ms-c-recursive-solution/3
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isScramble(const string& s1, const string& s2) {
		if (s1 == s2) {
			return true;
		}
		if (s1.size() != s2.size()) {
			return false;
		}
		if (s1.size() == 1 && s2.size() == 1) {
			return s1 == s2;
		}
		const int NumberOfASCII = 256;
		int hashmap[NumberOfASCII] = {0};
		const int n = s1.size();
		for (int i = 0; i < n; ++i) {
			++hashmap[s1[i]];
			--hashmap[s2[i]];
		}
		for (int i = 0; i < NumberOfASCII; ++i) {
			if (hashmap[i]) {
				return false;
			}
		}
		for (int i = 1; i < n; ++i) {
			if (this->isScramble(s1.substr(0, i), s2.substr(0, i))
				&& this->isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) {
				return true;
			}
			if (this->isScramble(s1.substr(0, i), s2.substr(n - i, i))
				&& this->isScramble(s1.substr(i, n - i), s2.substr(0, n - i))) {
				return true;
			}
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	string s1 = "great";
	string s2 = "rgeat";
	if (solution.isScramble(s1, s2)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	s1 = "abc";
	s2 = "bca";
	if (solution.isScramble(s1, s2)) {
		cout << "\nPassed\n";		
	}
	else {
		cout << "\nError\n";
		return 0;		
	}
	cout << "\nPassed All\n";
	return 0;
}