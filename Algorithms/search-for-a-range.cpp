//34. Search for a Range
//https://leetcode.com/problems/search-for-a-range/
//https://github.com/soulmachine/leetcode
//http://www.cplusplus.com/reference/algorithm/lower_bound/
//http://www.cplusplus.com/reference/algorithm/upper_bound/
//http://www.cplusplus.com/reference/algorithm/equal_range/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> searchRange(const vector<int>& nums, const int& target) {
		vector<int> result(2, -1);
		if (nums.empty() || target > nums.back() || target < nums.front())
			return result;
		else {
			auto loit = lower_bound(nums.begin(), nums.end(), target);
			auto upit = --upper_bound(nums.begin(), nums.end(), target);
			if (*(loit) != target || *(upit) != target || distance(loit, upit) < 0)
				return result;
			else {
				result[0] = distance(nums.begin(), loit);
				result[1] = distance(nums.begin(), upit);
				return result;
			}
		}
	}
};
int main(void) {
	Solution solution;
	
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;

	//vector<int> nums = { 1 };
	//int target = 1;

	for (const auto& i : solution.searchRange(nums, target)) {
		cout << i << '\t';
	}
	cout << "\nPassed\n";
	getchar();
	return 0;
}

//34. Search for a Range
//https://leetcode.com/problems/search-for-a-range/
//https://github.com/soulmachine/leetcode
//http://www.cplusplus.com/reference/algorithm/lower_bound/
//http://www.cplusplus.com/reference/algorithm/upper_bound/
//http://www.cplusplus.com/reference/algorithm/equal_range/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(const vector<int>& nums, const int& target) {
		vector<int> result(2, -1);
		if (nums.empty() || target > nums.back() || target < nums.front())
			return result;
		else {
			int loIdx = this->lowerBound(nums, target);
			int hiIdx = this->upperBound(nums, target);
			--hiIdx;
			if (nums[loIdx] != target || nums[hiIdx] != target || loIdx > hiIdx) {
				return result;
			}
			else {
				result[0] = loIdx;
				result[1] = hiIdx;
				return result;
			}
		}
	}
	int lowerBound(const vector<int>& nums, const int& target) {
		int first = 0;
		int last = nums.size();
		int count = last - first;
		while (count > 0) {
			int i = first, step = count / 2;
			i += step;
			if (nums[i] < target) {
				first = ++i;
				count -= step + 1;
			}
			else
				count = step;
		}
		return first;
	}
	int upperBound(const vector<int>& nums, const int& target) {
		int first = 0;
		int last = nums.size();
		int count = last - first;
		while (count > 0) {
			int i = first, step = count / 2;
			i += step;
			if (!(target < nums[i])) {
				first = ++i;
				count -= step + 1;
			}
			else
				count = step;
		}
		return first;
	}
};
int main(void) {
	Solution solution;
	
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;

	//vector<int> nums = { 1 };
	//int target = 1;

	for (const auto& i : solution.searchRange(nums, target)) {
		cout << i << '\t';
	}
	cout << "\nPassed\n";
	getchar();
	return 0;
}
