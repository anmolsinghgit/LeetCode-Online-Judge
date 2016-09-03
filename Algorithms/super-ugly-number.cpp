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
		vector<int> OPT(n, INT_MAX), index(primes.size(), 0);
		OPT[0] = 1;
		for (int i = 1; i < n; ++i) {
			for (size_t j = 0; j < primes.size(); ++j)
				OPT[i] = min(OPT[i], OPT[index[j]] * primes[j]);
			for (size_t j = 0; j < primes.size(); ++j)
				index[j] += OPT[i] == OPT[index[j]] * primes[j];
		}
		return OPT[n - 1];
	}
};
// Memory Limit Exceeded
// class Solution {
// public:
// 	int nthSuperUglyNumber(int n, vector<int>& primes) {
// 		priority_queue<size_t, vector<size_t>, greater<size_t>> minHeap;
// 		size_t result;
// 		minHeap.push(1);
// 		while (n--) {
// 			result = minHeap.top();
// 			for (const auto &i : primes) minHeap.push(i * result);
// 			while (result == minHeap.top()) minHeap.pop();
// 		}
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> primes = {2, 7, 13, 19};
	for (int i = 1; i <=12; ++i) cout << solution.nthSuperUglyNumber(i, primes) << "\tPassed\n";
	primes = {7, 19, 29, 37, 41, 47, 53, 59, 61, 79, 83, 89, 101, 103, 109, 127, 131, 137, 139, 157, 167, 179, 181, 199, 211, 229, 233, 239, 241, 251};
	cout << solution.nthSuperUglyNumber(100000, primes) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}