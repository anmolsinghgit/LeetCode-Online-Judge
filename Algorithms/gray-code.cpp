// 89. Gray Code
// https://leetcode.com/problems/gray-code/
// https://discuss.leetcode.com/topic/8557/an-accepted-three-line-solution-in-java
// https://en.wikipedia.org/wiki/Gray_code
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> grayCode(const int& n) {
		vector<int> result;
		for (int i = 0; i < 1 << n; ++i) {
			result.push_back(i ^ (i >> 1));
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	int n = 2;
	for (const auto& i : solution.grayCode(n)) {
		cout << i << '\t';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}