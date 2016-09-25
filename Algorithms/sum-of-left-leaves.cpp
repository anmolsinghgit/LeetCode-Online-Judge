// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		TreeNode *parent = NULL;
		int result = 0;
		this->sumOfLeftLeaves(root, parent, result);
		return result;
	}
private:
	void sumOfLeftLeaves(TreeNode* root, TreeNode* parent, int& result) {
		if (!root) return;
		if (parent && parent->left == root && !root->left && !root->right) result += root->val;
		this->sumOfLeftLeaves(root->left, root, result);
		this->sumOfLeftLeaves(root->right, root, result);
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	cout << solution.sumOfLeftLeaves(root) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}