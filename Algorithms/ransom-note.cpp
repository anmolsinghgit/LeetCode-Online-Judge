// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/
// https://discuss.leetcode.com/topic/53864/java-o-n-solution-easy-to-understand
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int hashmap[26] = {0};
		for (const auto &i : magazine) ++hashmap[i - 'a'];
		for (const auto &i : ransomNote) if (--hashmap[i - 'a'] < 0) return false;
		return true;
	}
};
int main(void) {
	Solution solution;
	cout << boolalpha << solution.canConstruct("a", "b") << "\tPassed\n";
	cout << boolalpha << solution.canConstruct("aa", "ab") << "\tPassed\n";
	cout << boolalpha << solution.canConstruct("aa", "aab") << "\tPassed\n";
	cout << "\nPassed\n";
	return 0;
}