// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<string>> partition(const string& s) {
		vector<vector<string>> result;
		if (s.empty()) return result;
		for (size_t i = 1; i <= s.size(); ++i) {
			if (this->isPalindrome(s.substr(0, i))) {
				if (i == s.size()) {
					vector<string> vec = {s};
					result.push_back(vec);
					return result;
				}
				vector<vector<string>> matrix = this->partition(s.substr(i));
				if (matrix.empty()) continue;
				for (auto &vec : matrix) {
					vec.insert(begin(vec), s.substr(0, i));
					result.push_back(vec);
				}

			}
		}
		return result;
	}
private:
	unordered_map<string, bool> hashMap;
	bool isPalindrome(const string& s) {
		if (s.empty()) return true;
		if (this->hashMap.count(s)) return this->hashMap.find(s)->second;
		for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
			if (s[i] != s[j]) {
				this->hashMap[s] = false;
				return false;
			}
		}
		this->hashMap[s] = true;
		return true;
	}
};
int main(void) {
	Solution solution;
	string s = "aab";
	for (const auto &i : solution.partition(s)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}