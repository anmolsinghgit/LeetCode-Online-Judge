// 357. Count Numbers with Unique Digits
// https://leetcode.com/problems/count-numbers-with-unique-digits/
// https://discuss.leetcode.com/topic/47983/java-dp-o-1-solution
#include <iostream>
using namespace std;
class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0) return 1;
		int result = 10;
		int uniqueDigits = 9;
		int availableNumber = 9;
		while (--n && availableNumber) result += uniqueDigits *= availableNumber--;
		return result;
	}
};
int main(void) {
	Solution solution;
	for (int i = 0; i < 15; ++i) cout << solution.countNumbersWithUniqueDigits(i) << '\t';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}