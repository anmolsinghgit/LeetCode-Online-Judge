// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// https://discuss.leetcode.com/topic/4407/accepted-short-solution-in-java/2
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		this->maxPathDown(root);
		return maxValue;
	}
private:
	int maxValue = INT_MIN;
	int maxPathDown(TreeNode* node) {
		if (!node) return 0;
		int left = max(0, this->maxPathDown(node->left));
		int right = max(0, this->maxPathDown(node->right));
		maxValue = max(maxValue, left + right + node->val);
		return max(left, right) + node->val;
	}
};
int main(void) {
	Solution solution;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	if (solution.maxPathSum(root) == 6) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}