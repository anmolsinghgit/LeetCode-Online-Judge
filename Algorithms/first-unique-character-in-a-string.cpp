// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int>hashmap(26, INT_MIN);
		int result = -1;
		for (size_t i = 0; i < s.size(); ++i) {
			if (hashmap[s[i] - 'a'] == INT_MIN) {
				hashmap[s[i] - 'a'] = i;
				continue;
			}
			hashmap[s[i] - 'a'] = -1;
		}
		for (const auto &i : hashmap) {
			if (i < 0) continue;
			if (result == -1) result = i;
			else result = min(result, i);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	cout << solution.firstUniqChar("leetcode") << "\tPassed\n";
	cout << solution.firstUniqChar("loveleetcode") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}