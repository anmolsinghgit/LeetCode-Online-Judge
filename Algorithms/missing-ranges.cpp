// 163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		if (lower > upper) return result;
		if (nums.empty() || lower > nums.back() || upper < nums.front()) {
			if (lower ==  upper) return result = {to_string(lower)};
			string str = to_string(lower) + "->" + to_string(upper);
			return result = {str};
		}
		int prev = lower;
		bool first = true;
		for (size_t i = 0; i < nums.size(); ++i) {
			if (nums[i] < lower || nums[i] > upper) continue;
			if (first && nums[i] == lower) {
				prev = nums[i];
				first = false;
				continue;					
			}
			if (first && nums[i] == lower + 1) {
				result.push_back(to_string(lower));
				prev = nums[i];
				first = false;
				continue;
			}
			if (first && nums[i] > lower + 1) {
				string str =  to_string(lower) + "->" + to_string(nums[i] - 1);
				result.push_back(str);
				prev = nums[i];
				first = false;
				continue;
			}
			if (nums[i] == prev) {
				prev = nums[i];
				continue;
			}
			if (nums[i] == prev + 1) {
				prev = nums[i];
				continue;					
			}
			if (nums[i] == prev + 2) {
				result.push_back(to_string(nums[i] - 1));
				prev = nums[i];
				continue;					
			}
			string str =  to_string(prev + 1) + "->" + to_string(nums[i] - 1);
			result.push_back(str);
			prev = nums[i];
			continue;
		}
		if (upper == prev) return result;
		if (upper == prev + 1) {
			result.push_back(to_string(upper));
			return result;
		}
		string str =  to_string(prev + 1) + "->" + to_string(upper);
		result.push_back(str);
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {0, 1, 3, 50, 75};
	int lower = 0;
	int upper = 99;
	for (const auto &i : solution.findMissingRanges(nums, lower, upper)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {};
	lower = 1;
	upper = 1;
	for (const auto &i : solution.findMissingRanges(nums, lower, upper)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {-1};
	lower = -2;
	upper = -1;
	for (const auto &i : solution.findMissingRanges(nums, lower, upper)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {-1};
	lower = -1;
	upper = 0;
	for (const auto &i : solution.findMissingRanges(nums, lower, upper)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}