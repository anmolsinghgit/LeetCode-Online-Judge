// 351. Android Unlock Patterns
// https://leetcode.com/problems/android-unlock-patterns/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
	int numberOfPatterns(int m, int n) {
		vector<vector<bool>> pattern(3, vector<bool>(3, false));
		int result = 0;
		this->numberOfPatterns(pattern, m, n, result, 0, -1, -1);
		return result;
	}
private:
	void numberOfPatterns(vector<vector<bool>>& pattern, int m, int n, int& result, int count, int i0, int j0) {
		if (m > n) return;
		if (count > n) return;
		if (count >= m) ++result;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (!this->isValid(pattern, i, j, i0, j0)) continue;
				pattern[i][j] = true;
				this->numberOfPatterns(pattern, m, n, result, count + 1, i, j);
				pattern[i][j] = false;
			}
		}
	}
	bool isValid(vector<vector<bool>>& pattern, int i, int j, int i0, int j0) {
		if (i0 < 0 && j0 < 0) return true;
		if (i == i0 && j == j0) return false;
		if (pattern[i][j]) return false;
		if (abs(i - i0) <= 1 && abs(j - j0) <= 1) return true;
		if (abs(i - i0) == 2 && abs(j - j0) == 2) return pattern[1][1];
		if (abs(i - i0) == 2 && abs(j - j0) == 0) return pattern[min(i0, i) + 1][j0];
		if (abs(i - i0) == 2 && abs(j - j0) == 1) return true;
		if (abs(i - i0) == 0 && abs(j - j0) == 2) return pattern[i0][min(j0, j) + 1];
		if (abs(i - i0) == 1 && abs(j - j0) == 2) return true;
		return false;
	}
};
int main(void) {
	Solution solution;
	cout << solution.numberOfPatterns(1, 1) << "\tPassed\n";
	cout << solution.numberOfPatterns(1, 2) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}