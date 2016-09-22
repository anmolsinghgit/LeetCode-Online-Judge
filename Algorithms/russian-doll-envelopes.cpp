// 354. Russian Doll Envelopes
// https://leetcode.com/problems/russian-doll-envelopes/
// https://discuss.leetcode.com/topic/47469/java-nlogn-solution-with-explanation
// http://www.cnblogs.com/grandyang/p/5568818.html
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		sort(begin(envelopes), end(envelopes), [](const pair<int, int>& i, const pair<int, int>& j) {if (i.first == j.first) return i.second > j.second; return i.first < j.first;});
		vector<int> result;
		for (const auto &i : envelopes) {
			vector<int>::iterator it = lower_bound(begin(result), end(result), i.second);
			if (it == end(result)) result.push_back(i.second);
			else *it = i.second;
		}
		return result.size();
	}
};
// class Solution {
// public:
// 	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
// 		sort(begin(envelopes), end(envelopes));
// 		const int n = envelopes.size();
// 		vector<int> OPT(n + 1, 0);
// 		int result = 0;
// 		for (int i = n - 1; i >= 0; --i) {
// 			int tmp = 0;
// 			for (int j = 1; i + j < n; ++j)
// 				if (envelopes[i + j].first > envelopes[i].first && envelopes[i + j].second > envelopes[i].second)
// 					tmp = max(tmp, OPT[i + j]);
// 			result = max(result, (OPT[i] = tmp + 1));
// 		}
// 		return result;
// 	}
// };
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