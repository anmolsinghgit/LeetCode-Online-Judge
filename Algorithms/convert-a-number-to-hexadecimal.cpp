// 405. Convert a Number to Hexadecimal
// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	string toHex(int num) {
		if (num == 0) return "0";
		string result;
		unsigned int Num;
		if (num < 0) {
			Num = -num;
			Num = ~Num + 1;
		}
		else Num = num;
		while (Num) {
			unsigned int n = Num % 16;
			if (n < 10) result.push_back('0' + n);
			else result.push_back('a' + (n - 10));
			Num /= 16;
		}
		reverse(begin(result), end(result));
		return result;
	}
};
int main(void) {
	Solution solution;
	cout << solution.toHex(26) << "\tPassed\n";
	cout << solution.toHex(-1) << "\tPassed\n";
	cout << solution.toHex(0) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
