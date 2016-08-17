// 201. Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/
// https://discuss.leetcode.com/topic/13508/one-line-c-solution
// https://discuss.leetcode.com/topic/12133/bit-operation-solution-java
#include <iostream>
using namespace std;
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		return (n > m) ? (this->rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
	}
};
int main(void) {
	Solution solution;
	int m = 5;
	int n = 7;
	cout << solution.rangeBitwiseAnd(m, n) << "\tPassed\n";
	m = 0;
	n = 2147483647;
	cout << solution.rangeBitwiseAnd(m, n) << "\tPassed\n";
	m = 20000;
	n = 2147483647;
	cout << solution.rangeBitwiseAnd(m, n) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}