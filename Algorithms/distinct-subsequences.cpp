// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/
// http://bangbingsyb.blogspot.ca/2014/11/leetcode-distinct-subsequences.html
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int numDistinct(const string& s, const string& t) {
		const size_t& m = s.size();
		const size_t& n = t.size();
		vector<vector<int>> OPT(m + 1, vector<int>(n + 1, 0));
		for (size_t i = 0; i < m + 1; ++i) OPT[i][0] = 1;
		for (size_t i = 1; i < m + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				if (s[i - 1] == t[j - 1]) OPT[i][j] = OPT[i - 1][j - 1] + OPT[i - 1][j];
				else OPT[i][j] = OPT[i - 1][j];
			}
		}
		return OPT[m][n];
	}
};
int main(void) {
	Solution solution;
	string s = "rabbbit";
	string t = "rabbit";
	if (solution.numDistinct(s, t) == 3) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		getchar();
		return 0;
	}
	s = "aacaacca";
	t = "ca";
	if (solution.numDistinct(s, t) == 5) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		getchar();
		return 0;
	}
	cout << "\nPassed All\n";
	getchar();
	return 0;
}
