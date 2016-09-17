// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		if (n <= 0) return 0;
		int r = sqrt(n);
		if (r * r == n) return 1;
		vector<int> OPT(1 + n, 0);
		for (int i = 1; i < n + 1; ++i) {
			int r = sqrt(i);
			if (r * r == i) OPT[i] = 1;
			else {
				int num = INT_MAX;
				for (int j = 1; j <= r; ++j) num = min(num, OPT[i - j * j]);
				OPT[i] = 1 + num;
			}
		}
		return OPT[n];
	}
};
int main(void) {
	Solution solution;
	cout << solution.numSquares(12) << "\tPassed\n";
	cout << solution.numSquares(13) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}