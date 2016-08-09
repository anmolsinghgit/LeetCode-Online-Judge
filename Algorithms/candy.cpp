// 135. Candy
// https://leetcode.com/problems/candy/
// https://discuss.leetcode.com/topic/5243/a-simple-solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
class Solution {
public:
	int candy(const vector<int>& ratings) {
		const int n = ratings.size();
		if (n <= 1) return n;
		vector<int> OPT(n, 1);
		for (int i = 1; i < n; ++i) if (ratings[i] > ratings[i - 1]) OPT[i] = max(OPT[i], 1 + OPT[i - 1]);
		for (int i = n - 2; i >= 0; --i) if (ratings[i] > ratings[i + 1]) OPT[i] = max(OPT[i], 1 + OPT[i + 1]);
		return accumulate(begin(OPT), end(OPT), 0);
	}
};
int main(void) {
	Solution solution;
	vector<int> ratings = {0};
	if (solution.candy(ratings) == 1) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	ratings = {2, 2};
	if (solution.candy(ratings) == 2) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	ratings = {1, 2};
	if (solution.candy(ratings) == 3) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}