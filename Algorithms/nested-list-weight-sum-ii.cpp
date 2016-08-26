// 364. Nested List Weight Sum II
// https://leetcode.com/problems/nested-list-weight-sum-ii/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
	int depthSumInverse(vector<NestedInteger>& nestedList) {
		return this->depthSumInverse(nestedList, this->depth(nestedList));
	}
private:
	int depth(const vector<NestedInteger>& nestedList) {
		if (nestedList.empty()) return 0;
		int result = 1;
		for (const auto &i : nestedList)
			if (!i.isInteger())
				result = max(result, 1 + this->depth(i.getList()));
		return result;
	}
	int depthSumInverse(const vector<NestedInteger>& nestedList, int depth) {
		int result = 0;
		for (const auto &i : nestedList) {
			if (i.isInteger()) result += depth * i.getInteger();
			else result += this->depthSumInverse(i.getList(), depth - 1);
		}
		return result;
	}
};