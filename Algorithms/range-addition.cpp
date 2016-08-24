// 370. Range Addition
// https://leetcode.com/problems/range-addition/
// https://discuss.leetcode.com/topic/49666/my-simple-c-solution
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int> result(length, 0);
		vector<int> nums(length + 1, 0);
		for (const auto &v : updates) {
			nums[v[0]] += v[2];
			nums[v[1] + 1] -= v[2];
		}
		int sum = 0;
		for (int i = 0; i < length; ++i) {
			sum += nums[i];
			result[i] = sum;
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	int length = 5;
	vector<vector<int>> updates = {{1,  3,  2}, {2,  4,  3}, {0,  2, -2}};
	for (const auto &i : solution.getModifiedArray(length, updates)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}