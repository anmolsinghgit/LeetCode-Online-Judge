// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPerfectSquare(int num) {
		size_t x = this->mySqrt(num);
		return x * x == num;
	}
private:
	int mySqrt(int x) {
		size_t r = x;
		while (r * r > x)
			r = (r + x / r) / 2;
		return r;
	}
};
int main(void) {
	Solution solution;
	cout << boolalpha << solution.isPerfectSquare(16) << "\tPassed\n";
	cout << boolalpha << solution.isPerfectSquare(14) << "\tPassed\n";
	return 0;
}