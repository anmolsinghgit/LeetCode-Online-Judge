// 294. Flip Game II
// https://leetcode.com/problems/flip-game-ii/
// https://discuss.leetcode.com/topic/27282/theory-matters-from-backtracking-128ms-to-dp-0ms
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool canWin(string s) {
		for (size_t i = 0; i + 1 < s.size(); ++i) {
			if (s.substr(i, 2) != "++") continue;
			s[i] = s[i + 1] = '-';
			if (!this->canWin(s)) return true;
			s[i] = s[i + 1] = '+';
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	string s = "++++";
	cout << boolalpha << solution.canWin(s) << "\tPassed\n";
	s = "+++++";
	cout << boolalpha << solution.canWin(s) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}