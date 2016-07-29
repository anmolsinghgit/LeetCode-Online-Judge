// 97. Interleaving String
// https://leetcode.com/problems/interleaving-string/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isInterleave(const string& s1, const string& s2, const string& s3) {
		const int len1 = s1.size();
		const int len2 = s2.size();
		const int len3 = s3.size();
		if (len1 + len2 != len3) {
			return false;
		}
		if (len1 == 0 && len2 == 0) {
			return len3 == 0;
		}
		if (len1 == 0 && len2 != 0) {
			return s2 == s3;
		}
		if (len1 != 0 && len2 == 0) {
			return s1 == s3;
		}
		const int ASCII_MAX = 256;
		int hashmap[ASCII_MAX] = {0};
		for (const auto& i : s1) {
			++hashmap[i];
		}
		for (const auto& i : s2) {
			++hashmap[i];
		}
		for (const auto& i : s3) {
			--hashmap[i];
		}
		for (int i = 0; i < ASCII_MAX; ++i) {
			if (hashmap[i]) {
				return false;
			}
		}
		bool OPT[len1 + 1][len2 + 1] = {false};
		for (int i = 0; i < len2 + 1; ++i) {
			OPT[len1][i] = s2.substr(i) == s3.substr(i + len1);
		}
		for (int i = 0; i < len1 + 1; ++i) {
			OPT[i][len2] = s1.substr(i) == s3.substr(i + len2);
		}
		for (int i = len1 - 1; i >= 0; --i) {
			for (int j = len2 - 1; j >= 0; --j) {
				if (s1[i] == s3[i + j] && s2[j] != s3[i + j]) {
					OPT[i][j] = OPT[i + 1][j];
				}
				else if (s1[i] != s3[i + j] && s2[j] == s3[i + j]) {
					OPT[i][j] = OPT[i][j + 1];
				}
				else if (s1[i] == s3[i + j] && s2[j] == s3[i + j]) {
					OPT[i][j] = OPT[i + 1][j] || OPT[i][j + 1];
				}
				else {
					OPT[i][j] = false;
				}
			}
		}
		return OPT[0][0];
	}
};
int main(void) {
	Solution solution;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	if (solution.isInterleave(s1, s2, s3)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	s3 = "aadbbbaccc";
	if (!solution.isInterleave(s1, s2, s3)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
	if (!solution.isInterleave(s1, s2, s3)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	s1 = "";
	s2 = "";
	s3 = "";
	if (solution.isInterleave(s1, s2, s3)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}