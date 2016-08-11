// 156. Binary Tree Upside Down
// https://leetcode.com/problems/binary-tree-upside-down/
// http://blog.csdn.net/whuwangyi/article/details/43186045
// https://lefttree.gitbooks.io/leetcode/content/binaryTree/binaryTreeUpsideDown.html
// https://discuss.leetcode.com/topic/18273/clean-java-solution
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
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		if (!root) return root;
		if (!root->left && !root->right) return root;
		TreeNode *rootleft = root->left;
		root->left = NULL;
		TreeNode *rootright = root->right;
		root->right = NULL;
		TreeNode *result = this->upsideDownBinaryTree(rootleft);
		if (rootleft) {
			rootleft->left = rootright;
			rootleft->right = root;
		}
		return result;
	}
};
void inorderTraverse(TreeNode* root) {
	if (!root) return;
	TreeNode *cur = root;
	while (cur) {
		if (!cur->left) {
			cout << cur->val << '\t';
			cur = cur->right;
			continue;
		}
		TreeNode *pred = cur->left;
		while(pred->right && pred->right != cur) pred = pred->right;
		if (!pred->right) {
			pred->right = cur;
			cur = cur->left;
			continue;
		}
		cout << cur->val << '\t';
		pred->right =  NULL;
		cur = cur->right;
		continue;
	}
}
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	cout << '\n';
	inorderTraverse(root);
	cout << '\n';
	root = solution.upsideDownBinaryTree(root);
	cout << '\n';
	inorderTraverse(root);
	cout << '\n';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}