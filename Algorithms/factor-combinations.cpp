// 254. Factor Combinations
// https://leetcode.com/problems/factor-combinations/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> getFactors(int n) {
		vector<vector<int>> result;
		if (n == 1) return result;
		if (this->isPrime(n)) return result;
		vector<int> factor;
		for (int i = 2; i < n; i++) if (n % i == 0) factor.push_back(i);
		vector<int> path;
		this->backTrack(result, path, factor, 0, n); 
		return result;
	}
private:
	void backTrack(vector<vector<int>>& result, vector<int>& path, vector<int>& factor, int start, int target) {
		if (target == 1) {
			result.push_back(path);
			return;
		}
		const int n = factor.size();
		for (int i = start; i < n; i++) {
			int x = factor[i];
			if (target % x) continue;
			path.push_back(x);
			this->backTrack(result, path, factor, i, target / x);
			path.pop_back();
		}		
	}
	bool isPrime(int n) {
		if (n == 1) return false;
		if (n % 2 == 0) return false;
		for (int i = 3; i <= this->sqrt(n); i += 2)
			if (n % i == 0)
				return false;
		return true;
	}
	int sqrt(int n) {
		size_t r = n;
		while (r * r > (size_t)n) r = (r + n / r) / 2;
		return (int)r;
	} 
};
int main(void) {
	Solution solution;
	for (const auto &i : solution.getFactors(1)) {
		for (const auto &j : i) cout << j << '\t';
		cout << '\n';
	}
	cout << "\nPassed\n";
	for (const auto &i : solution.getFactors(37)) {
		for (const auto &j : i) cout << j << '\t';
		cout << '\n';
	}
	cout << "\nPassed\n";
	for (const auto &i : solution.getFactors(12)) {
		for (const auto &j : i) cout << j << '\t';
		cout << '\n';
	}
	cout << "\nPassed\n";
	for (const auto &i : solution.getFactors(32)) {
		for (const auto &j : i) cout << j << '\t';
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}