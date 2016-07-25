// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int numDecodings(const string& s) {
		int result = 0;
		int length = s.size();
		int value = 0;
		if (length == 0) {
			return result = 0;
		}
		if (s[0] == '0') {
			return result = 0;
		}
		if (length == 1) {
			return result = 1;
		}
		if (length == 2) {
			value = stoi(s);
			if (value == 10 || value == 20) {
				return result = 1;
			}
			if (value >= 11 && value <= 19) {
				return result = 2;
			}
			if (value >= 21 && value <= 26) {
				return result = 2;
			}
			if (s[1] == '0') {
				return result = 0;
			}
			return result = 1;
		}
		vector<int> OPT(length, 0);
		OPT[length - 1] = this->numDecodings(s.substr(length - 1, 1));
		OPT[length - 2] = this->numDecodings(s.substr(length - 2, 2));
		for (int i = length - 3; i >= 0; --i) {
			value = stoi(s.substr(i, 1));
			OPT[i] = (value ? 1 : 0) * OPT[i + 1];
			value = stoi(s.substr(i, 2));
			OPT[i] += ((value >= 10 && value <= 26) ? 1 : 0) * OPT[i + 2];
		}
		return result = OPT[0];
	}
};
int main(void) {
	Solution solution;
	string s = "12";
	if (solution.numDecodings(s) == 2) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	s = "111";
	if (solution.numDecodings(s) == 3) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}