// 394. Decode String
// https://leetcode.com/problems/decode-string/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string decodeString(string s) {
		string result;
		for (size_t i = 0; i < s.size();) {
			if (s[i] >= '0' && s[i] <= '9') {
				vector<size_t> a;
				size_t j = i;
				while (i < s.size() && s[i] >= '0' && s[i] <= '9') i++;
				a.push_back(i);
				int b = stoi(s.substr(j, i - j));
				i++;
				while (i < s.size() && !a.empty()) {
					if (s[i] == '[') {
						a.push_back(i++);
						continue;
					}
					if (s[i] == ']') {
						size_t k = a.back();
						a.pop_back();
						if (a.empty()) {
							string t = this->decodeString(s.substr(k + 1, i - k - 1));
							while (b--) result += t;
							i++;
							continue;
						}
						i++;
						continue;
					}
					i++;
					continue;
				}
				continue;
			}
			result.push_back(s[i++]);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	cout << solution.decodeString("3[a]2[bc]") << "\tPassed\n";
	cout << solution.decodeString("3[a2[c]]") << "\tPassed\n";
	cout << solution.decodeString("2[abc]3[cd]ef") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}