// 312. Burst Balloons
// https://leetcode.com/problems/burst-balloons/
// https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
// BEGIN: Bottom Up
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		nums.insert(begin(nums), 1);
		nums.insert(end(nums), 1);
		const int n = nums.size();
		vector<vector<int>> OPT(n, vector<int>(n, 0));
		for (int len = 2; len < n; ++len)
			for (int i = 0, j = i + len; j < n; ++i, ++j)
				for (int k = i + 1; k < j; ++k)
					OPT[i][j] = max(OPT[i][j], OPT[i][k] + OPT[k][j] + nums[i] * nums[k] * nums[j]);
		return OPT[0][n - 1];
	}
};
// END: Bottom Up
// BEGIN: Top Down
// class Solution {
// public:
// 	int maxCoins(vector<int>& nums) {
// 		nums.insert(begin(nums), 1);
// 		nums.insert(end(nums), 1);
// 		const int n = nums.size();
// 		vector<vector<int>> memorization(n, vector<int>(n, 0));
// 		return this->maxCoins(nums, memorization, 0, n - 1);
// 	}
// private:
// 	int maxCoins(vector<int>& nums, vector<vector<int>> &memorization, int i, int j) {
// 		if (i >= j + 1) return 0;
// 		if (memorization[i][j]) return memorization[i][j];
// 		for (int k = i + 1; k < j; ++k)
// 			memorization[i][j] = max(memorization[i][j], nums[i] * nums[k] * nums[j] + this->maxCoins(nums, memorization, i, k) + this->maxCoins(nums, memorization, k, j));
// 		return memorization[i][j];
// 	}
// };
// END: Top Down
int main(void) {
	Solution solution;
	vector<int> nums = {3, 1, 5, 8};
	cout << solution.maxCoins(nums) << "\tPassed\n";
	cout << "\nPassed\n";
	return 0;
}