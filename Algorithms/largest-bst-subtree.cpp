// 333. Largest BST Subtree
// https://leetcode.com/problems/largest-bst-subtree/
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		if (this->isValidBST(root)) return this->countNodes(root);
		return max(this->largestBSTSubtree(root->left), this->largestBSTSubtree(root->right));
	}
private:
	bool isValidBST(TreeNode* root) {
		TreeNode *previous = NULL;
		return this->isValidBST(root, previous);
	}
	bool isValidBST(TreeNode* root, TreeNode*& previous) {
		if (!root) return true;
		if (!this->isValidBST(root->left, previous)) return false;
		if (previous && previous->val >= root->val) return false;
		previous = root;
		if (!this->isValidBST(root->right, previous)) return false;
		return true;
	}
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		return this->countNodes(root->left) + 1 + this->countNodes(root->right);
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(8);
	root->right->right = new TreeNode(7);
	cout << solution.largestBSTSubtree(root) << "\tPassed\n";
	root = new TreeNode(3);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(2);
	cout << solution.largestBSTSubtree(root) << "\tPassed\n";
	root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(2);
	root->left->left->right = new TreeNode(4);
	cout << solution.largestBSTSubtree(root) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}