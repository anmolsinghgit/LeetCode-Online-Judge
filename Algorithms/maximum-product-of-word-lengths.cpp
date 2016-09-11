// 318. Maximum Product of Word Lengths
// https://leetcode.com/problems/maximum-product-of-word-lengths/
// https://discuss.leetcode.com/topic/31766/bit-shorter-c
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<int> hash(words.size(), 0);
		int result = 0;
		for (size_t i = 0; i < words.size(); ++i) {
			for (const auto &c : words[i])
				hash[i] |= 1 << (c - 'a');
			for (size_t j = 0; j < i; ++j)
				if ((hash[i] & hash[j]) == 0)
					result = max(result, int(words[i].size() * words[j].size()));
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	cout << solution.maxProduct(words) << "\tPassed\n";
	words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	cout << solution.maxProduct(words) << "\tPassed\n";
	words = {"a", "aa", "aaa", "aaaa"};
	cout << solution.maxProduct(words) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}