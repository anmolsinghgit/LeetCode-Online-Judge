// 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/
// https://leetcode.com/discuss/26602/brief-c-solution-using-only-strings-and-without-reversal
// https://leetcode.com/discuss/71593/easiest-java-solution-with-graph-explanation
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string multiply(const string& num1, const string& num2) {
		size_t len1(num1.size());
		size_t len2(num2.size());
		//    num1 [len1] x num2 [len2]
		// <= 99...9 [len1] x 99...9 [len2]
		// =  (10 ^ len1 - 1) * (10 ^ len2 - 1)
		// =  10 ^ (len1 + len2) - 10 ^ len1 - 10 ^ len2 + 1
		// <= 10 ^ (len1 + len2) - 1
		// =  99...9 [len1 + len2]
		string result(len1 + len2, '0');
		for (size_t i = len1; i >= 1; --i) {
			int carry(0);
			for (size_t j = len2; j >= 1; --j) {
				int value = (num1[i - 1] - '0') * (num2[j - 1] - '0');
				value += result[i + j - 1] - '0';
				value += carry;
				result[i + j - 1] = value % 10 + '0';
				carry = value / 10;
			}
			result[i - 1] = carry + '0';
		}
		for (size_t i = 0; i < len1 + len2; ++i) {
			if (result[i] != '0')
				return result.substr(i, len1 + len2 - i);
		}
		return string(1, '0');
	}
};
int main(void) {
	Solution solution;
	string num1("1234");
	string num2("345");
	cout << solution.multiply(num1, num2);
	cout << "\nPassed\n";
	return 0;
}
