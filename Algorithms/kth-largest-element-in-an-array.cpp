// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <queue>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		this->buildMaxHeap(nums);
		int result = 0;
		while (k--) {
			result = nums[0];
			swap(nums[0], nums[--this->heapSize]);
			this->maxHeapify(nums, 0);
		}
		return result;
	}
private:
	int heapSize;
	inline int left(int idx) {return (idx << 1) + 1;}
	inline int right(int idx) {return (idx << 1) + 2;}
	void maxHeapify(vector<int>& nums, int idx) {
		int largest = idx;
		int l = this->left(idx), r = this->right(idx);
		if (l < this->heapSize && nums[l] > nums[largest]) largest = l;
		if (r < this->heapSize && nums[r] > nums[largest]) largest = r;
		if (largest == idx) return;
		swap(nums[largest], nums[idx]);
		this->maxHeapify(nums, largest);
	}
	void buildMaxHeap(vector<int>& nums) {
		this->heapSize = nums.size();
		for (int i = (this->heapSize >> 1) - 1; i >= 0; --i) this->maxHeapify(nums, i);
	}
};
// class Solution {
// public:
// 	int findKthLargest(vector<int>& nums, int k) {
// 		priority_queue<int> pq(begin(nums), end(nums));
// 		while (--k) pq.pop();
// 		return pq.top();
// 	}
// };
// class Solution {
// public:
// 	int findKthLargest(vector<int>& nums, int k) {
// 		int left = 0, right = nums.size() - 1;
// 		while (true) {
// 			int i = this->partition(nums, left, right);
// 			if (i == k - 1) return nums[i];
// 			if (i < k - 1) left = i + 1;
// 			else right = i - 1;
// 		}
// 		return -1;
// 	}
// private:
// 	int partition(vector<int>& nums, int left, int right) {
// 		int i = left + 1, j = right, pivot = nums[left];
// 		while (i <= j) {
// 			if (nums[i] < pivot && nums[j] > pivot) swap(nums[i++], nums[j--]);
// 			if (nums[i] >= pivot) i++;
// 			if (nums[j] <= pivot) j--;
// 		}
// 		swap(nums[left], nums[j]);
// 		return j;
// 	}
// };
// class Solution {
// public:
// 	int findKthLargest(vector<int>& nums, int k) {
// 		int left = 0, right = nums.size() - 1, n = nums.size();
// 		while (true) {
// 			int i = this->partition(nums, left, right);
// 			if (i == n - k) return nums[i];
// 			if (i < n - k) left = i + 1;
// 			else right = i - 1;
// 		}
// 		return -1;
// 	}
// private:
// 	int partition(vector<int>& nums, int left, int right) {
// 		int pivot = nums[left], i = left + 1, j = right;
// 		while (i <= j) {
// 			if (nums[i] > pivot && nums[j] < pivot) swap(nums[i++], nums[j--]);
// 			if (nums[i] <= pivot) i++;
// 			if (nums[j] >= pivot) j--;
// 		}
// 		swap(nums[left], nums[j]);
// 		return j;
// 	}
// };
// class Solution {
// public:
// 	int findKthLargest(vector<int>& nums, int k) {
// 		sort(begin(nums), end(nums));
// 		return nums[nums.size() - k];
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums = {3, 2, 1, 5, 6, 4}; 
	int k = 2;
	cout << solution.findKthLargest(nums, k) << "\tPassed\n";
	nums = {3, 3, 3, 3, 4, 3, 3, 3, 3};
	k = 1;
	cout << solution.findKthLargest(nums, k) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}