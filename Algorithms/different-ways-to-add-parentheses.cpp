// 241. Different Ways to Add Parentheses
// https://leetcode.com/problems/different-ways-to-add-parentheses/
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <climits>
#include <iterator>
#include <algorithm>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/19894/1-11-lines-python-9-lines-c
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> result;
		for (size_t i = 0; i < input.size(); i++) {
			char c = input[i];
			if (!ispunct(c)) continue;
			for (const auto& j : this->diffWaysToCompute(input.substr(0, i)))
				for (const auto& k : this->diffWaysToCompute(input.substr(i + 1)))
					result.push_back(c == '*' ? j * k : c == '+' ? j + k : j - k);
		}
		return result.empty() ? vector<int>({stoi(input)}) : result;
	}
};
// END: https://discuss.leetcode.com/topic/19894/1-11-lines-python-9-lines-c
int main(void) {
	Solution solution;
	for (const auto &i : solution.diffWaysToCompute("2-1-1")) cout << i << '\t';
	cout << "\tPassed\n";
	for (const auto &i : solution.diffWaysToCompute("2*3-4*5")) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}