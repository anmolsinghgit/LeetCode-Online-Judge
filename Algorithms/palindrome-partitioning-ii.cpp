// 132. Palindrome Partitioning II
// https://leetcode.com/problems/palindrome-partitioning-ii/
// https://discuss.leetcode.com/topic/2840/my-solution-does-not-need-a-table-for-palindrome-is-it-right-it-uses-only-o-n-space/2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minCut(const string& s) {
		const int n = s.size();
		vector<int> OPT(n + 1, 0);
		for (int i = 0; i < n + 1; ++i) OPT[i] = i - 1;
		for (int i = 0; i < n + 1; ++i) {
			for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j) OPT[i + j + 1] = min(OPT[i + j + 1], 1 + OPT[i - j]);
			for (int j = 0; i - j >= 0 && i + j < n + 1 && s[i - j] == s[i + j - 1]; ++j) OPT[i + j] = min(OPT[i + j], 1 + OPT[i - j]);
		}
		return OPT[n];
	}
};
int main(void) {
	Solution solution;
	string s = "aab";
	if (solution.minCut(s) == 1) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}