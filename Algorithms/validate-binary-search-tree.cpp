// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// class Solution {
// public:
// 	bool isValidBST(TreeNode* root) {
// 		TreeNode *previous = NULL;
// 		while (root) {
// 			if (!root->left) {
// 				if (previous && previous->val >= root->val) return false;
// 				previous = root;
// 				root = root->right;
// 				continue;
// 			}
// 			TreeNode *predecessor = root->left;
// 			while (predecessor->right && predecessor->right != root) predecessor = predecessor->right;
// 			if (!predecessor->right) {
// 				predecessor->right = root;
// 				root = root->left;
// 				continue;
// 			}
// 			if (previous && previous->val >= root->val) return false;
// 			predecessor->right = NULL;
// 			previous = root;
// 			root = root->right;
// 		}
// 		return true;
// 	}
// };
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode *predecessor = NULL;
		return this->isValidBST(root, predecessor);
	}
private:
	bool isValidBST(TreeNode* root, TreeNode* &predecessor) {
		if (!root) return true;
		if (!this->isValidBST(root->left, predecessor)) return false;
		if (predecessor && root->val <= predecessor->val) return false;
		predecessor = root;
		if (!this->isValidBST(root->right, predecessor)) return false;
		return true;
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	cout << boolalpha << solution.isValidBST(root) << "\tPassed\n";
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout << boolalpha << solution.isValidBST(root) << "\tPassed\n";
	root = new TreeNode(1);
	root->left = new TreeNode(1);
	cout << boolalpha << solution.isValidBST(root) << "\tPassed\n";
	root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(20);
	cout << boolalpha << solution.isValidBST(root) << "\tPassed\n";
	cout << "\nPassed All\n";
}