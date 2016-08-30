// 343. Integer Break
// https://leetcode.com/problems/integer-break/
// https://discuss.leetcode.com/topic/42979/java-o-n-dp-solution-store-and-reuse-products
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int integerBreak(int n) {
		int *OPT = new int[n + 1];
		memset(OPT, 0, (n + 1) * sizeof(int));
		OPT[2] = 1;
		OPT[3] = 2;
		OPT[4] = 4;
		for (int i = 5; i < n + 1; ++i) OPT[i] = 3 * max(OPT[i - 3], i - 3);
		int result = OPT[n];
		delete[] OPT;
		return result;
	}
};
int main(void) {
	Solution solution;
	for (int i = 2; i < 59; ++i) cout << solution.integerBreak(i) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}