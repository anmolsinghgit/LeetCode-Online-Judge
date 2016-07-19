#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <climits>
using namespace std;
class Solution {
public:
	string minWindow(const string& s, const string& t) {
		if (s.empty() || t.empty()) {
			return string("");
		}
		const int NumberOfASCII(256);
		int expectedHashmap[NumberOfASCII] = {0};
		for (const auto& i : t) {
			++expectedHashmap[int(i)];
		}
		int appearedHashmap[NumberOfASCII] = {0};
		size_t i(0);
		size_t j(0);
		int left(0);
		int right(0);
		int distance(INT_MAX);
		int counter(t.size());
		while (j < s.size()) {
			if (expectedHashmap[int(s[j])] > 0) {
				if (appearedHashmap[int(s[j])] < expectedHashmap[int(s[j])]) {
					--counter;
				}
				++appearedHashmap[int(s[j])];
			}
			while (counter == 0) {
				if (j - i < distance) {
					left = i;
					right = j;
					distance = right - left;
				}
				if (expectedHashmap[int(s[i])] == 0) {
					++i;
				}
				else if (appearedHashmap[int(s[i])] > expectedHashmap[int(s[i])]) {
					--appearedHashmap[int(s[i])];
					++i;
				}
				else {
					--appearedHashmap[int(s[i])];
					++i;
					++counter;										
				}
			}
			++j;
		}
		if (distance == INT_MAX) {
			return string("");
		}
		else {
			return string(begin(s) + left, begin(s) + right + 1);
		}
	}
};
int main(void) {
	Solution solution;
	vector<string> S({"ADOBECODEBANC"});
	vector<string> T({"ABC"});
	vector<string> Z({"BANC"});
	for (size_t i(0); i < Z.size(); ++i) {
		string output(solution.minWindow(S[i], T[i]));
		cout << output << '\n';
		if (Z[i] == output) {
			cout << "\nPassed\n";
		}
		else {
			cout << "\nError\n";
			return 0;
		}
	}
	cout << "\nPassed All\n";
	return 0;
}