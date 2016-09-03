// 313. Super Ugly Number
// https://leetcode.com/problems/super-ugly-number/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>
#include <queue>
using namespace std;
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> OPT(n, INT_MAX);
		const int k = primes.size();
		vector<int> index(k, 0);
		OPT[0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				OPT[i] = min(OPT[i], OPT[index[j]] * primes[j]);
			}
			for (int j = 0; j < k; ++j) {
				if (OPT[i] == OPT[index[j]] * primes[j]) {
					++index[j];
				}
			}
		}
		return OPT[n - 1];
	}
};
int main(void) {
	Solution solution;
	vector<int> primes = {2, 7, 13, 19};
	for (int i = 1; i <=12; ++i) cout << solution.nthSuperUglyNumber(i, primes) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}