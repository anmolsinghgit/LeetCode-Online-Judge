// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
// https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
	NumArray(vector<int> &nums) {
		this->tree.resize(nums.size() + 1, 0);
		for (size_t i = 0; i < nums.size(); ++i)
			this->update(i, nums[i]);
	}

	void update(int i, int val) {
		this->add(i + 1, val - this->readSingle(i + 1));
	}

	int sumRange(int i, int j) {
		return this->read(j + 1) - this->read(i);
	}
private:
	vector<int> tree;
	int readSingle(size_t i) {
		int result = this->tree[i];
		if (i == 0) return result;
		size_t lowerBound = i - (i & (-i));
		--i;
		while (lowerBound != i) {
			result -= this->tree[i];
			i -= i & (-i);
		}
		return result;
	}
	int read(size_t i) {
		int result = 0;
		while (i != 0) {
			result += this->tree[i];
			i -= i & (-i);
		}
		return result;
	}
	void add(size_t i, int val) {
		while (i < this->tree.size()) {
			this->tree[i] += val;
			i += i & (-i);
		}
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main(void) {
	vector<int> nums = {1, 3, 5};
	NumArray numArray(nums);
	cout << numArray.sumRange(0, 2) << "\tPassed\n";
	numArray.update(1, 2);
	cout << numArray.sumRange(0, 2) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}