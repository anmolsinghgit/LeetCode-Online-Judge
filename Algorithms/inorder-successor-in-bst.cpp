// 285. Inorder Successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/
// https://discuss.leetcode.com/category/355/inorder-successor-in-bst
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
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (p->right) {
			root = p->right;
			while (root->left) root = root->left;
			return root;
		}
		TreeNode *successor = NULL;
		while (root) root = (root->val > p->val) ? (successor = root)->left : root->right;
		return successor;
	}
};
int main(void) {
	Solution solution;
	TreeNode* root = new TreeNode(15);
	root->left = new TreeNode(6);
	root->right = new TreeNode(18);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(7);
	root->right->left = new TreeNode(17);
	root->right->right = new TreeNode(20);
	root->left->left->left = new TreeNode(2);
	root->left->left->right = new TreeNode(4);
	root->left->right->right = new TreeNode(13);
	root->left->right->right->left = new TreeNode(9);
	cout << solution.inorderSuccessor(root, root)->val << "\tPassed\n";
	cout << solution.inorderSuccessor(root, root->left->right->right)->val << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}