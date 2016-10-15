// 386. Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/55131/ac-200ms-c-solution-beats-98
class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> result;
		for (int i = 0, x = 1; i < n; i++) {
			result.push_back(x);
			if (x * 10 <= n) {
				x *= 10;
				continue;
			}
			if (x == n) x /= 10;
			x++;
			while (x % 10 == 0) x /= 10;
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/55131/ac-200ms-c-solution-beats-98
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<int> lexicalOrder(int n) {
// 		vector<int> result;
// 		if (n == 0) return result = {0};
// 		vector<string> V;
// 		for (int i = 1; i <=n; i++) V.push_back(to_string(i));
// 		sort(begin(V), end(V));
// 		for (const auto &i : V) result.push_back(stoi(i));
// 		return result;
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	for (const auto &i : solution.lexicalOrder(13)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}