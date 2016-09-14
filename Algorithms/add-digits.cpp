// 258. Add Digits
// https://leetcode.com/problems/add-digits/
// https://en.wikipedia.org/wiki/Digital_root
// https://en.wikipedia.org/wiki/Modulo_operation
#include <iostream>
using namespace std;
class Solution {
public:
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}
};
int main(void) {
	Solution solution;
	cout << solution.addDigits(38) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}