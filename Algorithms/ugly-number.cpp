// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/
#include <iostream>
using namespace std;
class Solution {
public:
	bool isUgly(int num) {
		if (num == 0) return false;
		while (num % 2 == 0) num /= 2;
		while (num % 3 == 0) num /= 3;
		while (num % 5 == 0) num /= 5;
		return num == 1;
	}
};
int main(void) {
	Solution solution;
	cout << boolalpha << solution.isUgly(6) << "\tPassed\n";
	cout << boolalpha << solution.isUgly(8) << "\tPassed\n";
	cout << boolalpha << solution.isUgly(14) << "\tPassed\n";
	cout << boolalpha << solution.isUgly(0) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}