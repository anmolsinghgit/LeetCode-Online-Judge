// 32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std; 
class Solution {
public:
	int longestValidParentheses(const string& s) {
	int result = 0;
	stack<int> lefts;
	int last = -1;
	// ") ( ) ( ) )"
	//  0 1 2 3 4 5
	//  _____________________
	// | i | lefts | last    |
	// | 0 | NULL  | 0       |
	// | 1 | 1     | 0       |
	// | 2 | NULL  | 0       |
	// | 3 | 3     | 0       |
	// | 4 | NULL  | 0       |
	// | 5 | NULL  | 5       |
	//  _____________________
	// "( ( )"
	//  0 1 2
	//  __________________
	// | i | lefts | last |
	// | 0 | 0     | -1   |
	// | 1 | 0 1   | -1   |
	// | 2 | 0     | -1   |
	//  __________________
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			lefts.push(i);
		else {
			if (lefts.empty())
				last = i;
			else {
				lefts.pop();
				if (lefts.empty()) 
					result = max(result, i - last);
				else 
					result = max(result, i - lefts.top());
			}
	}
}
return result;
}
};
int main(void) {
	Solution solution;
	// string s = ")()())";
	string s = "(()";
	cout << solution.longestValidParentheses(s) << "\nPassed\n";
	getchar();
	return 0;
}