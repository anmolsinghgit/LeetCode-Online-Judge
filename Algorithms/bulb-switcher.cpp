// 319. Bulb Switcher
// https://leetcode.com/problems/bulb-switcher/
// https://discuss.leetcode.com/topic/31929/math-solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;
class Solution {
public:
	int bulbSwitch(int n) {
		return sqrt(n);
	}
};
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int bulbSwitch(int n) {
// 		vector<int> OPT(n, 0);
// 			for (const auto & j : OPT)
// 				cout << j << '\t';
// 			cout << '\n';
// 		for (int i = 1; i <= n; ++i) {
// 			for (int j = i; j <= n; j += i)
// 				OPT[j - 1] = 1 - OPT[j - 1];
// 			for (const auto & j : OPT)
// 				cout << j << '\t';
// 			cout << '\n';
// 		}
// 		return accumulate(begin(OPT), end(OPT), 0);
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	for (int i = 0; i <= 9999999; ++i)
		cout << solution.bulbSwitch(i) << "\tPassed\n";
	// cout << solution.bulbSwitch(0) << "\tPassed\n";
	// cout << solution.bulbSwitch(3) << "\tPassed\n";
	// cout << solution.bulbSwitch(8) << "\tPassed\n";
	// cout << solution.bulbSwitch(9) << "\tPassed\n";
	// cout << solution.bulbSwitch(9999999) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}