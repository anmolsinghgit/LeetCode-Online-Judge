// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
// https://discuss.leetcode.com/topic/44226/c-o-n-log-n-k-unordered_map-and-priority_queue-maxheap-solution
// https://discuss.leetcode.com/topic/44337/simple-c-solution-using-hash-table-and-bucket-sort
#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> hashmap;
		for (const auto &i : nums) ++hashmap[i];
		priority_queue<pair<int, int>> pq;
		for (const auto &i : hashmap) pq.push(make_pair(i.second, i.first));
		vector<int> result;
		while (k--) {
			result.push_back(pq.top().second);
			pq.pop();
		}
		return result;
	}
};
// class Solution {
// public:
// 	vector<int> topKFrequent(vector<int>& nums, int k) {
// 		unordered_map<int, int> hashmap;
// 		for (const auto &i : nums) ++hashmap[i];
// 		vector<vector<int>> buckets(nums.size() + 1);
// 		for (const auto &i : hashmap) buckets[i.second].push_back(i.first);
// 		vector<int> result;
// 		for (int i = nums.size(); i >= 0 && result.size() < k; --i) result.insert(end(result), begin(buckets[i]), end(buckets[i]));
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	for (const auto &i : solution.topKFrequent(nums, k)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}