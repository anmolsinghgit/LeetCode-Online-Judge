// 220. Contains Duplicate III
// https://leetcode.com/problems/contains-duplicate-iii/
// https://discuss.leetcode.com/topic/18453/c-using-set-less-10-lines-with-simple-explanation/
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <cstdlib>
using namespace std;
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<int> RBT;
		for (size_t i = 0; i < nums.size(); ++i) {
			if ((int)i > k) RBT.erase(nums[i - k - 1]);
			// x - nums[i] >= -t <=> x >= nums[i] - t;
			set<int>::iterator it = RBT.lower_bound(nums[i] - t);
			// x - nums[i] <= t
			if (it != end(RBT) && *it - nums[i] <= t) return true;
			RBT.insert(nums[i]);
		}
		return false;
	}
};
// class Solution {
// public:
// 	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
// 		if (t < 0 || k < 0) return false;
// 		set<int> RBT;
// 		for (size_t i = 0; i < nums.size(); ++i) {
// 			if ((int)i > k) RBT.erase(nums[i - k - 1]);
// 			set<int>::iterator predecessor = RBT.lower_bound(nums[i]), successor = RBT.upper_bound(nums[i]);
// 			if (RBT.empty()) {
// 				RBT.insert(nums[i]);
// 				continue;
// 			}
// 			if (predecessor == end(RBT)) {
// 				if (nums[i] <= *(--predecessor) + t) return true;
// 				RBT.insert(nums[i]);
// 				continue;
// 			}
// 			if (*predecessor == nums[i]) return true;
// 			if (predecessor == begin(RBT)) {
// 				if (*predecessor <= t + nums[i]) return true;
// 				RBT.insert(nums[i]);
// 				continue;				
// 			}
// 			if (successor == end(RBT)) {
// 				if (nums[i] <= t + *(--successor)) return true;
// 				RBT.insert(nums[i]);
// 				continue;				
// 			}
// 			if (abs(*(--predecessor) - nums[i]) <= t) return true;
// 			if (abs(*successor - nums[i]) <= t) return true;
// 			RBT.insert(nums[i]);
// 		}
// 		return false;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums;
	cout << boolalpha << solution.containsNearbyAlmostDuplicate(nums, 0, 0) << "\tPassed\n";
	nums = {7, 2, 8};
	cout << boolalpha << solution.containsNearbyAlmostDuplicate(nums, 2, 1) << "\tPassed\n";
	nums = {-1, -1};
	cout << boolalpha << solution.containsNearbyAlmostDuplicate(nums, 1, 0) << "\tPassed\n";
	nums = {-1, -1};
	cout << boolalpha << solution.containsNearbyAlmostDuplicate(nums, 1, -1) << "\tPassed\n";
	nums = {4, 2};
	cout << boolalpha << solution.containsNearbyAlmostDuplicate(nums, 2, 1) << "\tPassed\n";
	nums = {-1, -1};
	cout << boolalpha << solution.containsNearbyAlmostDuplicate(nums, 1, -1) << "\tPassed\n";
	nums = {-1, 2147483647};
	cout << boolalpha << solution.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << "\tPassed\n";
	// set<int> test({2, 1, 3, 0, -1, -2});
	// for (auto it = begin(test); it != end(test); ++it) cout << *it << '\t';
	// cout << '\n' << *(--test.lower_bound(1000)) << '\t';
	cout << "\nPassed All\n";
	return 0;
}