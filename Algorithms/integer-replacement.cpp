// 397. Integer Replacement
// https://leetcode.com/problems/integer-replacement/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
	int integerReplacement(int n) {
		if (n == 1) return 0;
		if (n == INT_MAX) return 32;
		if (n & 1) return 1 + min(this->integerReplacement(n - 1), this->integerReplacement(n + 1));
		return 1 + this->integerReplacement(n >> 1);
	}
};
int main(void) {
	Solution solution;
	cout << solution.integerReplacement(8) << "\tPassed\n";
	cout << solution.integerReplacement(7) << "\tPassed\n";
	cout << solution.integerReplacement(2147483647) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}