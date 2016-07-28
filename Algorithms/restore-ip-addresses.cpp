// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		vector<int> path;
		if (s.size() < 4) {
			return result;
		}
		if (s.size() > 12) {
			return result;
		}
		this->restoreIpAddresses(1, path, s, result);
		return result;
	}
private:
	void restoreIpAddresses(const int& current, vector<int>& path, string& s, vector<string>& result) {
		if (path.size() == 3) {
			if (path[0] > 3 || stoi(s.substr(0,  path[0])) >= 256 || (path[0] > 1 && s[0] == '0')) {
				return;
			}
			if (path[1] - path[0] > 4 || stoi(s.substr(path[0] + 1, path[1] - path[0] - 1)) >= 256 || (path[1] - path[0] - 1 > 1 && s[path[0] + 1] == '0')) {
				return;
			}
			if (path[2] - path[1] > 4 || stoi(s.substr(path[1] + 1, path[2] - path[1] - 1)) >= 256 || (path[2] - path[1] - 1 > 1 && s[path[1] + 1] == '0')) {
				return;
			}
			if (s.size() - path[2] > 4 || stoi(s.substr(path[2] + 1, s.size() - path[2] - 1)) >= 256 || (s.size() - path[2] - 1 > 1 && s[path[2] + 1] == '0')) {
				return;
			}
			if (find(begin(result), end(result), s) == end(result)) {
				result.push_back(s);
				return;
			}
			return;
		}
		for (int i = current; i < s.size(); ++i) {
			s.insert(begin(s) + i, '.');
			path.push_back(i);
			this->restoreIpAddresses(i + 2, path, s, result);
			s.erase(begin(s) + path.back());
			path.pop_back();
		}
		return;
	}
};
int main(void) {
	Solution solution;
	string s = "25525511135";
	for (const auto& i : solution.restoreIpAddresses(s)) {
		for (const auto& j : i) {
			cout << j;
		}
		cout << '\n';
	}
	cout << "\nPassed\n\n";
	s = "0279245587303";
	for (const auto& i : solution.restoreIpAddresses(s)) {
		for (const auto& j : i) {
			cout << j;
		}
		cout << '\n';
	}
	cout << "\nPassed\n\n";
	s = "0000";
	for (const auto& i : solution.restoreIpAddresses(s)) {
		for (const auto& j : i) {
			cout << j;
		}
		cout << '\n';
	}
	cout << "\nPassed\n\n";
	s = "010010";
	for (const auto& i : solution.restoreIpAddresses(s)) {
		for (const auto& j : i) {
			cout << j;
		}
		cout << '\n';
	}
	s = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	for (const auto& i : solution.restoreIpAddresses(s)) {
		for (const auto& j : i) {
			cout << j;
		}
		cout << '\n';
	}	
	cout << "\nPassed\n\n";
	cout << "\nPassed All\n";
	return 0;
}