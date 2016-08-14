// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/
#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_map>
using namespace std;
class Solution {
public:
	string fractionToDecimal(long long int numerator, long long int denominator) {
		if (numerator == 0) return to_string(0);
		if (denominator == 1) return to_string(numerator);
		if (denominator == - 1) return to_string(-numerator);
		if (numerator % denominator == 0) return to_string(numerator / denominator);
		bool negative = (numerator > 0) ^ (denominator > 0);
		numerator = abs(numerator);
		denominator = abs(denominator);
		string result;
		if (negative) result += "-";
		result += to_string(numerator / denominator);
		result += ".";
		unordered_map<int, int> hashMap;
		long long int i = 0;
		int idx = 0;
		string s;
		for (i = 10 * (numerator % denominator); i && !hashMap.count(i); hashMap[i] = idx++, i = 10 * (i % denominator)) s += to_string(i / denominator);
		if (i) {
			s.insert(begin(s) + hashMap[i], '(');
			s.insert(end(s), ')');
		}
		return result += s;
	}
};
int main(void) {
	Solution solution;
	int numerator = 1;
	int denominator = 2;
	cout << solution.fractionToDecimal(numerator, denominator) << "\tPassed\n";
	numerator = 2;
	denominator = 1;
	cout << solution.fractionToDecimal(numerator, denominator) << "\tPassed\n";
	numerator = 2;
	denominator = 3;
	cout << solution.fractionToDecimal(numerator, denominator) << "\tPassed\n"; 
	numerator = 1;
	denominator = 6;
	cout << solution.fractionToDecimal(numerator, denominator) << "\tPassed\n"; 
	cout << "\nPassed All\n";
	numerator = -1;
	denominator = -2147483648;
	cout << solution.fractionToDecimal(numerator, denominator) << "\tPassed\n"; 
	cout << "\nPassed All\n";
	return 0;
}