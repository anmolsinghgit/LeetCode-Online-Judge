// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minDistance(const string& word1, const string& word2) {
		const int m = word1.size();
		const int n = word2.size();
		vector<vector<int>> OPT(m + 1, vector<int>(n + 1, 0));
		for (int i(0); i < m + 1; ++i) {
			OPT[i][0] = i;
		}
		for (int j(0); j < n + 1; ++j) {
			OPT[0][j] = j;
		}
		for (int i(1); i < m + 1; ++i) {
			for (int j(1); j < n + 1; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					OPT[i][j] = OPT[i - 1][j - 1];
				}
				else {
					OPT[i][j] = min(OPT[i - 1][j - 1] + 1, OPT[i][j - 1] + 1);
					OPT[i][j] = min(OPT[i][j], OPT[i - 1][j] + 1);
				}
			}
		}
		return OPT[m][n];
	}
};
int main(void) {
	Solution solution;
	vector<string> A({"", "sea", "a"});
	vector<string> B({"a", "eat", "b"});
	vector<int> C({1, 2, 1});
	for (size_t i(0); i < C.size(); ++i) {
		if (C[i] ^ solution.minDistance(A[i], B[i])) {
			cout << "\nError\n";
			return 0;
		}
		else {
			cout << "\nPassed\n";
		}
	}
	cout << "\nPassed All\n";
	return 0;
}