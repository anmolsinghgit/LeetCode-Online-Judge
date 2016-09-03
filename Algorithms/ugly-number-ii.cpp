// 264. Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/
// https://discuss.leetcode.com/topic/21882/my-16ms-c-dp-solution-with-short-explanation
// http://fisherlei.blogspot.ca/2015/10/leetcode-ugly-number-ii-solution.html
// https://discuss.leetcode.com/topic/22206/java-solution-with-one-min-heap
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> OPT(n, 1);
		for (int i = 1, i2 = 0, i3 = 0, i5 = 0; i < n; ++i) {
			OPT[i] = min(OPT[i2] * 2, min(OPT[i3] * 3, OPT[i5] * 5));
			if (OPT[i] == OPT[i2] * 2) i2++;
			if (OPT[i] == OPT[i3] * 3) i3++;
			if (OPT[i] == OPT[i5] * 5) i5++;
		}
		return OPT[n - 1];
	}
};
int main(void) {
	Solution solution;
	for (int i = 1; i <= 10; ++i) cout << solution.nthUglyNumber(i) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}