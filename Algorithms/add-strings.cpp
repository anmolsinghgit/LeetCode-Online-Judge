// 415. Add Strings
// https://leetcode.com/problems/add-strings/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1 == "0") return num2;
		if (num2 == "0") return num1;
		if (num1.size() < num2.size()) swap(num1, num2);
		reverse(begin(num1), end(num1));
		reverse(begin(num2), end(num2));
		const size_t m = num1.size(), n = num2.size();
		int carry = 0;
		for (size_t i = 0; i < m; i++) {
			if (i < n) {
				int val1 = num1[i] - '0', val2 = num2[i] - '0';
				int val = val1 + val2 + carry;
				num1[i] = '0' + val % 10;
				carry = val / 10;
				continue;
			}
			int val = num1[i] - '0' + carry;
			num1[i] = '0' + val % 10;
			carry = val / 10;
		}
		if (carry) num1.push_back('0' + carry);
		reverse(begin(num1), end(num1));
		return num1;
	}
};
int main(void) {
	Solution solution;
	cout << solution.addStrings("9", "99") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}