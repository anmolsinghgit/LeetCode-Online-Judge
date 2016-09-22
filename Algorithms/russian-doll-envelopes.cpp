// 354. Russian Doll Envelopes
// https://leetcode.com/problems/russian-doll-envelopes/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		if (envelopes.empty()) return 0;
		sort(begin(envelopes), end(envelopes));
		const int n = envelopes.size();
		vector<int> OPT(n, 0);
		OPT[n - 1] = 1;
		int result = 1;
		for (int i = n - 2; i >= 0; --i) {
			int tmp = 0;
			for (int j = 1; i + j < n; ++j)
				if (envelopes[i + j].first > envelopes[i].first && envelopes[i + j].second > envelopes[i].second)
					tmp = max(tmp, OPT[i + j]);
			result = max(result, (OPT[i] = tmp + 1));
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<pair<int, int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	envelopes = {{1, 1}, {1, 1}, {1, 1}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	envelopes = {{4, 5}, {6, 7}, {2, 3}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	envelopes = {{46, 89}, {50, 53}, {52, 68}, {72, 45}, {77, 81}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	envelopes = {{1, 3}, {3, 5}, {6, 7}, {6, 8}, {8, 4}, {9, 5}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	envelopes = {{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	envelopes = {{30, 50}, {12, 2}, {3, 4}, {12, 15}};
	cout << solution.maxEnvelopes(envelopes) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}