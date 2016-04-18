//1. Two Sum
//https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index;
		index.resize(2);
		vector<int> sortedNums(nums);
		sort(sortedNums.begin(), sortedNums.end());
		int i = 0;
		int j = sortedNums.size() - 1;
		while ((sortedNums[i] + sortedNums[j]) != target) {
			if ((sortedNums[i] + sortedNums[j]) < target) {
				++i;
			}
			else {
				--j;
			}
		}
		vector<int>::iterator it;
		vector<int>::iterator jt;
		it = find(nums.begin(), nums.end(), sortedNums[i]);
		jt = find(nums.begin(), it, sortedNums[j]);
		if (jt == it) {
			jt = find(it + 1, nums.end(), sortedNums[j]);
		}
		int index_i;
		index_i = distance(nums.begin(), it);
		int index_j;
		index_j = distance(nums.begin(), jt);
		index[0] = min(index_i, index_j);
		index[1] = max(index_i, index_j);
		return index;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	getchar();
	return 0;
}
