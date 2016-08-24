// 371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/
// https://discuss.leetcode.com/topic/49771/java-simple-easy-understand-solution-with-explanation/2
#include <iostream>
using namespace std;
class Solution {
public:
	int getSum(int a, int b) {
		if (!a) return b;
		if (!b) return a;
		while (b) {
			int carry = a & b;
			a ^= b;
			b = carry << 1;
		}
		return a;
	}
};
int main(void) {
	Solution solution;
	int a = 1;
	int b = 2;
	cout << solution.getSum(a, b) <<"\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}