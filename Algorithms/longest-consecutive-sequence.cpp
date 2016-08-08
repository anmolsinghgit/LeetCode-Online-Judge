// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/
// https://discuss.leetcode.com/topic/6148/my-really-simple-java-o-n-solution-accepted/2
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
	int longestConsecutive(const vector<int>& nums) {
		int result = 0;
		unordered_map<int, int> hashMap;
		for (const auto &num : nums) {
			if (!hashMap.count(num)) {
				int left = hashMap.count(num - 1) ? hashMap[num - 1] : 0;
				int right = hashMap.count(num + 1) ? hashMap[num + 1] : 0;
				int sum = left + 1 + right;
				hashMap[num] = sum;
				hashMap[num - left] = sum;
				hashMap[num + right] = sum;
				result = max(result, sum);
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {100, 4, 200, 1, 3, 2};
	if (solution.longestConsecutive(nums) == 4) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}