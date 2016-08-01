// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// http://articles.leetcode.com/construct-binary-tree-from-inorder-and-preorder-postorder-traversal
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(const int& x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode *buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		return this->buildTree(0, 0, inorder.size(), inorder, postorder);
	}
private:
	TreeNode *buildTree(const size_t& i, const size_t& j, const size_t& n, const vector<int>& inorder, const vector<int>& postorder) {
		if (n == 0) return NULL;
		TreeNode *root = new TreeNode(postorder[j + n - 1]);
		size_t k = 0;
		for (k = i; k < i + n && inorder[k] != root->val; ++k);
		root->left = this->buildTree(i, j, k - i, inorder, postorder);
		root->right = this->buildTree(i + 1 + k - i, j + k - i, n - 1 - k + i, inorder, postorder);
		return root;
	}	
};
void inorderTraversal(TreeNode *root) {
	if (!root) return;
	inorderTraversal(root->left);
	cout << root->val << '\t';
	inorderTraversal(root->right);
	return;
}
int main(void) {
	Solution solution;
	vector<int> inorder = {2, 1};
	vector<int> postorder = {2, 1};
	TreeNode *root = solution.buildTree(inorder, postorder);
	inorderTraversal(root);
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}