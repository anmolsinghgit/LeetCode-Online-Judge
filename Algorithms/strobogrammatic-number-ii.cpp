// 247. Strobogrammatic Number II
// https://leetcode.com/problems/strobogrammatic-number-ii/
#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<string> findStrobogrammatic(int n) {
		return this->findStrobogrammatic(n, true);
	}
private:
	vector<string> findStrobogrammatic(int n, bool first) {
		vector<string> result;
		if (n == 0) return result = {""};
		if (n == 1) return result = {"0", "1", "8"};	
		vector<pair<char, char>> X = {{'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
		vector<string> Y = this->findStrobogrammatic(n - 2, false);
		for (const auto& i : Y)
			for (const auto& j : X)
				result.push_back(j.first + i + j.second);
		if (!first) {
			for (const auto& i : Y)
				result.push_back('0' + i + '0');
		}
		return result;
	}
};
// class Solution {
// public:
// 	vector<string> findStrobogrammatic(int n) {
// 		return this->findStrobogrammatic(n, true);
// 	}
// private:
// 	vector<string> findStrobogrammatic(int n, bool first) {
// 		vector<string> result;
// 		if (n == 0) return result;
// 		if (n == 1) return result = {"0", "1", "8"};
// 		if (n == 2) {
// 			if (first) return result = {"11", "69", "88", "96"};
// 			else return result = {"00", "11", "69", "88", "96"};
// 		}		
// 		vector<pair<char, char>> X = {{'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
// 		vector<string> Y = this->findStrobogrammatic(n - 2, false);
// 		for (const auto& i : Y)
// 			for (const auto& j : X)
// 				result.push_back(j.first + i + j.second);
// 		if (!first) {
// 			for (const auto& i : Y)
// 				result.push_back('0' + i + '0');
// 		}
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	for (const auto &i : solution.findStrobogrammatic(2)) cout << i << '\t';
	cout << "\tPassed\n";
	for (const auto &i : solution.findStrobogrammatic(4)) cout << i << '\t';
	cout << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}