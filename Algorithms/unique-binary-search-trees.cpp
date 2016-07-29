// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int numTrees(const int& n) {
		vector<int> OPT(n + 1, 0);
		OPT[0] = 1;
		OPT[1] = 1;
		OPT[2] = 2;
		for (int i = 3; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				OPT[i] += OPT[j - 1] * OPT[i - j];
			}
		}
		return OPT[n];
	}
};
int main(void) {
	Solution solution;
	int n = 3;
	if (solution.numTrees(n) == 5) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}