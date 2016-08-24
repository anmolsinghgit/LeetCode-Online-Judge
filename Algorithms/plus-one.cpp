// 66. Plus One
// https://leetcode.com/problems/plus-one/
// https://discuss.leetcode.com/topic/24288/my-simple-java-solution
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; --i) {
			if (digits[i] < 9) {
				++digits[i];
				return digits;
			}
			digits[i] = 0;
		}
		digits.front() = 1;
		digits.push_back(0);
		return digits;
	}
};
int main(void) {
	Solution solution;
	vector<int> digits = {1, 0, 9, 9, 9};
	for (const auto &i : solution.plusOne(digits)) cout << i << '\t';\
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}