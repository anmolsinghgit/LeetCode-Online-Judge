// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		vector<int> stack;
		size_t i = 0;
		while (i < tokens.size()) {
			if (isdigit(tokens[i].back())) {
				int val = stoi(tokens[i]);
				stack.push_back(val);
				++i;
				continue;
			}
			int second = stack.back();
			stack.pop_back();
			int first = stack.back();
			stack.pop_back();
			int result = 0;
			if (tokens[i] == "+") result = first + second;
			else if (tokens[i] == "-") result = first - second;
			else if (tokens[i] == "*") result = first * second;
			else result = first / second;
			stack.push_back(result);
			++i;
			continue;
		}
		return stack.back();
	}
};
int main(void) {
	Solution solution;
	vector<string> tokens = {"0", "3", "/"};
	if (solution.evalRPN(tokens) == 0) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	tokens = {"-3", "9", "*"};
	if (solution.evalRPN(tokens) == -27) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	tokens = {"18"};
	if (solution.evalRPN(tokens) == 18) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}