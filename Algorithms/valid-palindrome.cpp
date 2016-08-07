// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
// https://discuss.leetcode.com/topic/5581/here-s-a-clean-c-solution/2
// http://www.cplusplus.com/reference/cctype/isalnum/
// http://www.cplusplus.com/reference/cctype/toupper/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Solution {
public:
	bool isPalindrome(const string& s) {
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
			while(!isalnum(s[i]) && i < j) ++i;
			while(!isalnum(s[j]) && i < j) --j;
			if (toupper(s[i]) != toupper(s[j])) return false;
		}
		return true;
	}
};
int main(void) {
	Solution solution;
	string s = "A man, a plan, a canal: Panama";
	if (solution.isPalindrome(s)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	s = "race a car";
	if (!solution.isPalindrome(s)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}