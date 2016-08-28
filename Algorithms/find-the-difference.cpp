// 389. Find the Difference
// https://leetcode.com/problems/find-the-difference/
// https://discuss.leetcode.com/topic/55912/java-solution-using-bit-manipulation
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	char findTheDifference(string s, string t) {
		char result = 0;
		for (const auto &i : s) result ^= i;
		for (const auto &i : t) result ^= i;
		return result;
	}
};
int main(void) {
	Solution solution;
	cout << solution.findTheDifference("abcd", "abcde") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}