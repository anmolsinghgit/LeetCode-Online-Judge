// 114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// https://discuss.leetcode.com/topic/11444/my-short-post-order-traversal-java-solution-for-share
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
	void flatten(TreeNode* root) {
		if (!root) return;
		this->flatten(root->right);
		this->flatten(root->left);
		root->right = previous;
		root->left = NULL;
		previous = root;
		return;
	}
private:
	TreeNode *previous = NULL;
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(6);
	solution.flatten(root);
	TreeNode *current = root;
	while (current) {
		cout << current->val << '\t';
		current = current->right;
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}