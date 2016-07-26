//1. Two Sum
//https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(const vector<int>& nums, const int& target) {
		unordered_map<int, int> hashmap;
		vector<int> result(2, 0);
		for (int i = 0; i < nums.size(); ++i) {
			int rest = target - nums[i];
			if (hashmap.count(rest)) {
				result[0] = hashmap[rest];
				result[1] = i;
				return result;
			}
			hashmap[nums[i]] = i;
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	for (const auto& i : solution.twoSum(nums,  target)) {
		cout << i << '\t';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";	
	return 0;
}
