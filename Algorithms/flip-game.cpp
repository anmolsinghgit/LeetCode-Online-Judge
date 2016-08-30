// 293. Flip Game
// https://leetcode.com/problems/flip-game/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> result;
		for (size_t i = 0; i + 1 < s.size(); ++i) {
			if (s[i] != '+' || s[i + 1] != '+') continue;
			s[i + 1] = s[i] = '-';
			result.push_back(s);
			s[i + 1] = s[i] = '+';
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	string s = "++++";
	for (const auto &i : solution.generatePossibleNextMoves(s)) cout << i << '\n';
	cout << "\nPassed\n";
	s = "--";
	for (const auto &i : solution.generatePossibleNextMoves(s)) cout << i << '\n';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}