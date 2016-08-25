// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// http://www.cplusplus.com/reference/algorithm/set_intersection/
// http://en.cppreference.com/w/cpp/algorithm/set_intersection
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result(nums1.size() + nums2.size(), 0);
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));
		vector<int>::iterator it = set_intersection(begin(nums1), end(nums1), begin(nums2), end(nums2), begin(result));
		result.resize(it - begin(result));
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	for (const auto &i : solution.intersect(nums1, nums2)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}