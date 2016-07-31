// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
// https://discuss.leetcode.com/topic/17357/morris-traversal-o-1-space-no-recursion-o-n-time-with-explanation-java
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(const int& x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		return this->isValidBST(root->left) && this->check(root) && this->isValidBST(root->right);
	}
private:
	bool check(TreeNode* root) {
		if (!predecessor) {
			predecessor = root;
			return true;
		}
		if (predecessor->val >= root->val) return false;
		predecessor = root;
		return true;
	}
private:
	TreeNode* predecessor = NULL;
};
int main(void) {
	Solution solution;
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	if (solution.isValidBST(root)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	root->val = 1;
	root->left->val = 2;
	root->right->val = 3;
	if (!solution.isValidBST(root)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	delete root->left;
	root->left = NULL;
	delete root->right;
	root->right = NULL;
	root->val = 2147483647;
	if (solution.isValidBST(root)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	root->val = 1;
	root->left = new TreeNode(1);
	if (!solution.isValidBST(root)) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}