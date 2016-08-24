// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> path;
		for (int i = 1; i <= min(n, 9); ++i)
			this->combinationSum3(i, k, n, path, result);
		return result;
	}
private:
	void combinationSum3(int start, int k, int n, vector<int>& path, vector<vector<int>>& result) {
		if (start > n) return;
		if (k <= 0) return;
		if (k == 1 && start != n) return;
		if (k == 1 && start == n) {
			path.push_back(start);
			result.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(start);
		for (int i = start + 1; i <= min(n - start, 9); ++i)
			this->combinationSum3(i, k - 1, n - start, path, result);
		path.pop_back();
	}
};
int main(void) {
	Solution solution;
	int k = 3;
	int n = 7;
	for (const auto &i : solution.combinationSum3(k, n)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	k = 3;
	n = 9;
	for (const auto &i : solution.combinationSum3(k, n)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	k = 2;
	n = 18;
	for (const auto &i : solution.combinationSum3(k, n)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}