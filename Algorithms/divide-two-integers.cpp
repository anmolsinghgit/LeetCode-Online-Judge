//29. Divide Two Integers
//https://leetcode.com/problems/divide-two-integers/
#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
class Solution {
public:
	int divide(const int& dividend, const int& divisor) {
		int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
		if (divisor == 0 || (dividend == INT_MAX && abs(divisor) == 1) ||  (dividend == INT_MIN && abs(divisor) == 1))
			return (sign < 0) ? INT_MIN : INT_MAX;
		int result = 0;
		long long int Dividend(dividend);
		Dividend = abs(Dividend);
		long long int Divisor(divisor);
		Divisor = abs(Divisor);
		while (Dividend >= Divisor) {
			// cout << "Dividend = " << Dividend << '\n';
			// cout << "Divisor = " << Divisor << '\n';
			int n = 0;
			while (Dividend >= (Divisor << n)) {
				++n;
			}
			--n;
			int a_n = 0;
			while (Dividend >= 0) {
				Dividend -=  (Divisor << n);
				++a_n;
			}
			--a_n;
			Dividend +=  (Divisor << n);
			result += (a_n << n);
		}
		return (sign < 0) ? - result : result;
	}
};
/*
dividend = divisor * (a_n * 2 ^ n + a_(n-1) * 2 ^ (n - 1) + ... + a_1 * 2 ^ 1 + a_0 * 2 ^ 0) + reminder;
reminder < divisor;
result = a_n * 2 ^ n + a_(n-1) * 2 ^ (n - 1) + ... + a_1 * 2 ^ 1 + a_0 * 2 ^ 0;
result = a_n << n + a_(n-1) << (n - 1) + ... + a_1 << 1 + a_0 << 0;
dividend = divisor * (a_n << n + a_(n-1) << (n - 1) + ... + a_1 << 1 + a_0 << 0) + reminder;
result := 0;
while (dividend >= divisor) { 15 >= 3 --> 3 >= 3
	n := 0;
	while (dividend >= (divisor << n)) { // 15 >= (3 << n) --> 3 >= (3 << n)
		++n;
	}
	--n;
	// n = 2 --> n = 0
	a_n := 0;
	while (dividend >=0) {
		dividend -= (divisor << n);
		++a_n;
	}
	--a_n;
	// a_n = 1 --> a_n = 1
	dividend += (divisor << n);
	// dividend = 3 --> dividend = 0
	result += (a_n << n);
}	
*/
int main(int argc, char** agrv) {
	Solution solution;
	int dividend = -2147483647;
	int divisor = 2;
	cout << dividend << '/' << divisor << '=' << solution.divide(dividend, divisor) << '\n';
	cout << "Passed!\n";
	return 0;
}
