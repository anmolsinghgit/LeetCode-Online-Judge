// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/
// https://discuss.leetcode.com/topic/12820/an-easy-c-8-lines-code-only-reversing-till-half-and-then-compare
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
		int sum = 0;
		while (x > sum) {
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		return (x == sum) || (x == sum / 10);
	}
};
int main(void) {
	Solution solution;
	int x = 121;
	if (solution.isPalindrome(x)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}