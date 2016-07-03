#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		return false;
	}
};
int main(void) {
	Solution solution;
	vector<string> a({"aa", "aa", "aaa", "aa", "aa", "ab", "aab", "b"});
	vector<string> b({"a", "aa", "aa", "*", "a*", "?*", "c*a*b", "*?*?"});
	vector<bool> c({false, true, false, true, true, true, false, false});
	for (size_t i(0); i < a.size(); ++i) {
		if (c[i] ^ solution.isMatch(a[i], b[i])) {
			cout << "\nError\n";
			return 0;
		}
	}
	cout << "\nPassed\n";
	return 0;
}
