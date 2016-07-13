// 65. Valid Number
// https://leetcode.com/problems/valid-number/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isNumber(const string& s) {
		if (s.empty()) {
			return false;
		}
		int indexOfSpace(-1);
		int numOfSign(0);
		int indexOfSign(-1);
		int indexOfDot(-1);
		int indexOfNumeric(-1);
		int numOfE(0);
		int indexOfE(-1);
		for (size_t i(0); i < s.size(); ++i) {
			if (indexOfSpace != -1) {
				if (indexOfDot != -1 && indexOfDot < indexOfSpace) {
					if (s[i] != ' ') {
						return false;
					}
				}
				if (indexOfNumeric != -1 && indexOfNumeric < indexOfSpace) {
					if (s[i] != ' ') {
						return false;
					}
				}
				if (indexOfE != -1 && indexOfE < indexOfSpace) {
					if (s[i] != ' ') {
						return false;
					}
				}
				if (indexOfSign != -1 && indexOfSign < indexOfSpace) {
					if (s[i] != ' ') {
						return false;
					}
				}
			}
			if (indexOfE != -1) {
				if (s[i] < '0' || s[i] > '9') {
					if (i == indexOfE + 1 && s[i] != '-' && s[i] != '+') {
						return false;
					}
				}

			}
			if (s[i] == ' ') {
				indexOfSpace = i;
			}
			else if (s[i] == '-' || s[i] == '+') {
				if (numOfSign >= 2) {
					return false;
				}
				if (i + 1 == s.size()) {
					return false;
				}
				if (i > 0) {
					if (s[i - 1] != 'e') {
						if (indexOfDot + indexOfSign + indexOfE + indexOfNumeric != -4) {
							return false;
						}
					}
				}
				indexOfSign = i;
				++numOfSign;
			}
			else if (s[i] == 'e') {
				if (i + 1 == s.size()) {
					return false;
				}
				if (numOfE >= 2) {
					return false;
				}
				if (indexOfE == -1) {
					if (indexOfNumeric == -1) {
						return false;
					}
					else {
						indexOfE = i;
						++numOfE;
					}
				}
				else {
					return false;
				}
			}
			else if (s[i] == '.') {
				if (indexOfDot == -1) {
					if (indexOfE != -1) {
						return false;
					}
					else {
						indexOfDot = i;
					}
				}
				else {
					return false;
				}
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				indexOfNumeric = i;
			}
			else {
				return false;
			}
		}
		return indexOfNumeric != -1;
	}
};
int main(void) {
	Solution solution;
	vector<string> a({ " 0.1 ", " 0", "abc", "1 a", "2e10", ".", "0e ", "-1.", " 005047e+6", "6+1", "4e+" });
	vector<bool> b({ true, true, false, false, true, false, false, true, true, false, false });
	for (size_t i(0); i < b.size(); ++i) {
		if (b[i] ^ solution.isNumber(a[i])) {
			cout << "\nError\n";
			getchar();
			return 0;
		}
		else
			cout << "\nPassed\n";
	}
	cout << "\nPassed All\n";
	getchar();
	return 0;
}