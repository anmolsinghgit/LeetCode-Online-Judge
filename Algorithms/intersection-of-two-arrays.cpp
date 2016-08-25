// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result(nums1.size() + nums2.size(), 0);
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));
		vector<int>::iterator it = begin(result), first = begin(nums1), second = begin(nums2);
		while (first != end(nums1) && second != end(nums2)) {
			if (*first < *second) {
				++first;
				continue;
			}
			if (*first > *second) {
				++second;
				continue;
			}
			*it = *first;
			while (first != end(nums1) && second != end(nums2) && *first == *it && *second == *it) {
				++first;
				++second;
			}
			++it;
		}
		result.resize(it - begin(result));
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	for (const auto &i : solution.intersection(nums1, nums2)) cout << i << '\t';
	cout << "\tPassed\n";
	nums1 = {2, 1};
	nums2 = {1, 2};
	for (const auto &i : solution.intersection(nums1, nums2)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}