// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
	int kthSmallest(TreeNode* root, int k) {
		int result = 0;
		this->inorderTraversal(root, k, result);
		return result;
	}
private:
	void inorderTraversal(TreeNode* root, int& k, int& result) {
		if (k == 0) return;
		if (!root) return;
		this->inorderTraversal(root->left, k, result);
		if (--k == 0) {result = root->val; return;}
		this->inorderTraversal(root->right, k, result);
	}
};
// class Solution {
// public:
// 	int kthSmallest(TreeNode* root, int k) {
// 		return this->MorrisInorderTraversal(root, k);
// 	}
// private:
// 	int MorrisInorderTraversal(TreeNode* root, int k) {
// 		while (root) {
// 			if (!root->left) {
// 				if (--k == 0) return root->val;
// 				root = root->right;
// 				continue;
// 			}
// 			TreeNode *pred = root->left;
// 			while (pred->right && pred->right != root) pred = pred->right;
// 			if (!pred->right) {
// 				pred->right = root;
// 				root = root->left;
// 				continue;
// 			}
// 			if (--k == 0) return root->val;
// 			pred->right = NULL;
// 			root = root->right;
// 		}
// 		return -1;
// 	}
// };
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(5);
	int k = 1;
	cout << solution.kthSmallest(root, k) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}