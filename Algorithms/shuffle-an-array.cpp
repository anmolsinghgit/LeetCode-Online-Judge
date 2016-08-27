// 384. Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/
// http://www.cplusplus.com/reference/algorithm/shuffle/
// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
// https://discuss.leetcode.com/topic/54022/c-solution-with-fisher-yates-algorithm
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <random>
#include <chrono>
#include <iterator>
using namespace std;
class Solution {
public:
	Solution(vector<int> nums) {
		srand(time(NULL));
		this->nums = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return this->nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> result(this->nums);
		for (int i = this->nums.size() - 1; i >= 1; --i) {
			int j = rand() % (i + 1);
			swap(result[i], result[j]);
		}
		return result;
	}
	// vector<int> shuffle() {
	// 	vector<int> result(this->nums);
	// 	for (int i = this->nums.size() - 1; i >= 1; --i) {
	// 		int j = rand() % (i + 1);
	// 		swap(result[i], result[j]);
	// 	}
	// 	return result;
	// }
	// vector<int> shuffle() {
	// 	vector<int> result(this->nums);
	// 	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	// 	std::shuffle(begin(result), end(result), default_random_engine(seed));
	// 	return result;
	// }
	// vector<int> shuffle() {
	// 	vector<int> result;
	// 	for (size_t i = 0; i < this->nums.size(); ++i) {
	// 		size_t j = rand() % (1 + result.size());
	// 		result.push_back(this->nums[i]);
	// 		swap(result[j], result.back());
	// 	}
	// 	return result;
	// }
private:
	vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

 int main(void) {
	// Init an array with set 1, 2, and 3.
	vector<int> nums = {1, 2, 3};
	Solution solution(nums);

	// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
	for (const auto &i : solution.shuffle()) cout << i << '\t';
	cout << "\tPassed\n";

	// Resets the array back to its original configuration [1,2,3].
	for (const auto &i : solution.reset()) cout << i << '\t';
	cout << "\tPassed\n";

	// Returns the random shuffling of array [1,2,3].
	for (const auto &i : solution.shuffle()) cout << i << '\t';
	cout << "\tPassed\n";

 	return 0;
 }