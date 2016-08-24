// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/
// https://discuss.leetcode.com/topic/21785/2-4-lines-every-language
#include <iostream>
using namespace std;
class Solution {
public:
	bool isUgly(int num) {
		for (int i = 2; i < 6 && num; ++i)
			while (num % i == 0)
				num /= i;
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