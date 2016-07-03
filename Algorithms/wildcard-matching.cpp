// 44. Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/
// https://discuss.leetcode.com/topic/3040/linear-runtime-and-constant-space-solution
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool isMatch(const string& s, const string& p) {
		return this->isMatch(s.c_str(), p.c_str());
	}
private:
	bool isMatch(const char *s, const char *p) {
		const char* star = NULL;
		const char* ss = s;
		while (*s) {
			if (*p == '?' || *p == *s) { ++s; ++p; continue; }
			if (*p == '*') { star = p++; ss = s; continue; }
			if (star) { p = star + 1; s = ++ss; continue; }
			return false;
		}
		while (*p == '*') ++p;
		return *p == '\0';
	}
};
int main(void) {
	Solution solution;
	vector<string> a({ "", "aa", "aa", "aaa", "aa", "aa", "ab", "aab", "b", "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb" });
	vector<string> b({ "*", "a", "aa", "aa", "*", "a*", "?*", "c*a*b", "*?*?", "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
"**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb" });
	vector<bool> c({ true, false, true, false, true, true, true, false, false, false });
	for (size_t i(0); i < a.size(); ++i) {
		if (c[i] ^ solution.isMatch(a[i], b[i])) {
			cout << "\nError\n";
			getchar();
			return 0;
		}
	}
	cout << "\nPassed\n";
	getchar();
	return 0;
}
