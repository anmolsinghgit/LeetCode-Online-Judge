// 400. Nth Digit
// https://leetcode.com/problems/nth-digit/
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
	int findNthDigit(size_t n) {
		if (n < 10) return n;
		size_t i = 1;
		for (i = 1; n >= 9 * i * size_t(pow(10, i - 1)); ++i) n -= 9 * i * size_t(pow(10, i - 1));
		size_t x = size_t(pow(10, i - 1)) + (n - 1) / i;
		return to_string(x)[(n - 1) % i] - '0';
	}
};
int main(void) {
	Solution solution;
	cout << solution.findNthDigit(3) << "\tPassed\n";
	cout << solution.findNthDigit(10) << "\tPassed\n";
	cout << solution.findNthDigit(11) << "\tPassed\n";
	cout << solution.findNthDigit(100) << "\tPassed\n";
	cout << solution.findNthDigit(1000000000) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}