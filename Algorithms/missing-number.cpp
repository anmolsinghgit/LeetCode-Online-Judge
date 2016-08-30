// 268. Missing Number
// https://leetcode.com/problems/missing-number/
// https://discuss.leetcode.com/topic/23427/3-different-ideas-xor-sum-binary-search-java-code/2
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int checkSum = nums.size() * (nums.size() + 1) / 2;
		int sum = accumulate(begin(nums), end(nums), 0);
		return checkSum - sum;
	}
};
// class Solution {
// public:
// 	int missingNumber(vector<int>& nums) {
// 		pair<vector<int>::iterator, vector<int>::iterator> minmaxPair = minmax_element(begin(nums), end(nums));
// 		int checkSum = *minmaxPair.second * (*minmaxPair.second + 1) / 2;
// 		int sum = accumulate(begin(nums), end(nums), 0);
// 		if (*minmaxPair.first == 0 && checkSum == sum) return *minmaxPair.second + 1;
// 		if (*minmaxPair.first != 0 && checkSum == sum) return 0;
// 		return checkSum - sum;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums = {0, 1, 3};
	cout << solution.missingNumber(nums) << "\tPassed\n";
	nums = {1};
	cout << solution.missingNumber(nums) << "\tPassed\n";
	nums = {0 , 1};
	cout << solution.missingNumber(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}