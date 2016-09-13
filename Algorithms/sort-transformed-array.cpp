// 360. Sort Transformed Array
// https://leetcode.com/problems/sort-transformed-array/
// https://discuss.leetcode.com/topic/48424/java-o-n-incredibly-short-yet-easy-to-understand-ac-solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
class Solution {
public:
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		vector<int> result;
		if (nums.empty()) return result;
		if (a == 0) {
			for (const auto& i : nums) result.push_back(this->transform(i, a, b, c));
			if (b < 0) reverse(begin(result), end(result));
			return result;
		}
		double peakIdx = double(-b) / double(2 * a);
		if ((a > 0 && peakIdx <= nums.front()) || (a < 0 && peakIdx >= nums.back())) {
			for (const auto& i : nums) result.push_back(this->transform(i, a, b, c));
			return result;
		}
		if ((a < 0 && peakIdx <= nums.front()) || (a > 0 && peakIdx >= nums.back())) {
			for (const auto& i : nums) result.push_back(this->transform(i, a, b, c));
			reverse(begin(result), end(result));
			return result;
		}
		int peakPoint = lower_bound(begin(nums), end(nums), peakIdx) - begin(nums);
		for (int i = peakPoint - 1, j = peakPoint; a > 0 && (i >= 0 || j < (int)nums.size()); ) {
			if (i < 0) {
				result.push_back(this->transform(nums[j++], a, b, c));
				continue;
			}
			if (j >= (int)nums.size()) {
				result.push_back(this->transform(nums[i--], a, b, c));
				continue;					
			}
			int left = this->transform(nums[i], a, b, c), right = this->transform(nums[j], a, b, c);
			if (left < right) {
				result.push_back(left);
				--i;
				continue;					
			}
			result.push_back(right);
			++j;
		}
		for (int i = 0, j = (int)nums.size() - 1; a < 0 && (i < peakPoint || j >= peakPoint); ) {
			if (i >= peakPoint) {
				result.push_back(this->transform(nums[j--], a, b, c));
				continue;					
			}
			if (j < peakPoint) {
				result.push_back(this->transform(nums[i++], a, b, c));
				continue;						
			}
			int left = this->transform(nums[i], a, b, c), right = this->transform(nums[j], a, b, c);
			if (left < right) {
				result.push_back(left);
				++i;
				continue;
			}
			result.push_back(right);
			--j;
		}
		return result;
	}
private:
	inline int transform(int x, int a, int b, int c) {
		return a * x * x + b * x + c;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {-4, -2, 2, 4};
	for (const auto &i : solution.sortTransformedArray(nums, 1, 3, 5)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {-4, -2, 2, 4};
	for (const auto &i : solution.sortTransformedArray(nums, -1, 3, 5)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {-4, -2, 2, 4};
	for (const auto &i : solution.sortTransformedArray(nums, 0, 3, 5)) cout << i << '\t';
	cout << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}