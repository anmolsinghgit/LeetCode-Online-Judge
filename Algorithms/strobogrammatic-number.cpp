// 246. Strobogrammatic Number
// https://leetcode.com/problems/strobogrammatic-number/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/20837/4-lines-in-java
class Solution {
public:
	bool isStrobogrammatic(string num) {
		const int n = num.size();
		if (n == 0) return true;
		string checkStr = "00 11 88 696";
		for (int i = 0, j = n - 1; i <= j; i++, j--) {
			string s;
			s.push_back(num[i]);
			s.push_back(num[j]);
			if (checkStr.find(s) == string::npos) return false;
		}
		return true;
	}
};
// END: https://discuss.leetcode.com/topic/20837/4-lines-in-java
// class Solution {
// public:
// 	bool isStrobogrammatic(string num) {
// 		const int n = num.size();
// 		if (n == 0) return true;
// 		vector<char> check({'0', '1', '8'});
// 		for (int i = 0, j = n - 1; i <= j; i++, j--) {
// 			if (i == j) return find(begin(check), end(check), num[i]) != end(check);
// 			if (num[i] == '6' && num[j] != '9') return false;
// 			if (num[i] == '9' && num[j] != '6') return false;
// 			if (num[i] == '6' && num[j] == '9') continue;
// 			if (num[i] == '9' && num[j] == '6') continue;
// 			if (find(begin(check), end(check), num[i]) == end(check)) return false;
// 			if (num[i] != num[j]) return false;
// 		}
// 		return true;
// 	}
// };
int main(void) {
	Solution solution;
	cout << boolalpha << solution.isStrobogrammatic("69") << "\tPassed\n";
	cout << boolalpha << solution.isStrobogrammatic("88") << "\tPassed\n";
	cout << boolalpha << solution.isStrobogrammatic("818") << "\tPassed\n";
	cout << boolalpha << solution.isStrobogrammatic("10") << "\tPassed\n";
	cout << boolalpha << solution.isStrobogrammatic("1") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}