// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/
// https://discuss.leetcode.com/topic/57151/3-lines-c
#include <iostream>
#include <string>
using namespace std;
// bool isSubsequence(char* s, char* t) {
// 	while (*t) s += *s == *t++;
// 	return !*s;
// }
class Solution {
public:
	bool isSubsequence(string s, string t) {
		return this->isSubsequence(s.data(), t.data());
	}
	bool isSubsequence(const char* x, const char* y) {
		while (*y) x += *x == *y++;
		return !*x;
	}
};
// class Solution {
// public:
// 	bool isSubsequence(string s, string t) {
// 		return this->isSubsequence(s.c_str(), t.c_str());
// 	}
// 	bool isSubsequence(const char* x, const char* y) {
// 		while (*y) x += *x == *y++;
// 		return !*x;
// 	}
// };
// class Solution {
// public:
// 	bool isSubsequence(string s, string t) {
// 		size_t i = 0, j = 0;
// 		while (j < t.size()) if (s[i] == t[j++]) i++;
// 		return i == s.size();
// 	}
// };
int main(void) {
	Solution solution;
	cout << boolalpha << solution.isSubsequence("abc", "ahbgdc") << "\tPassed\n";
	cout << boolalpha << solution.isSubsequence("axc", "ahbgdc") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}