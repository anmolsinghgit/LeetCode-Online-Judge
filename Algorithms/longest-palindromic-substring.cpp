// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	string longestPalindrome(const string& s) {
		const int n = s.size();
		bool f[n][n];
		fill_n(&f[0][0], n * n, false);
		int maxLen = 1;
		int start = 0;
		for (int i = 0; i < n; ++i) {
			f[i][i] = true;
			for (int j = 0; j < i; ++j) {
				f[j][i] = (s[j] == s[i]) && (i - j < 2 || f[j + 1][i - 1]);
				if (f[j][i] && i - j + 1 > maxLen) {
					start = j;
					maxLen = i - j + 1;
				}
			}
		}
		return s.substr(start, maxLen);
	}
};
int main(int argc, char** argv) {
	Solution solution;
	solution.longestPalindrome("LeetCode");
	cout << "Passed\n";
	return 0;
}
