// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://leetcode.com/articles/valid-anagram/
class Solution {
public:
	bool isAnagram(string s, string t) {
		sort(begin(s), end(s));
		sort(begin(t), end(t));
		return s == t;
	}
};
// END: https://leetcode.com/articles/valid-anagram/
int main(void) {
	Solution solution;
	cout << boolalpha << solution.isAnagram("anagram", "nagaram") << "\tPassed\n";
	cout << boolalpha << solution.isAnagram("rat", "car") << "\tPassed\n";
	return 0;
}