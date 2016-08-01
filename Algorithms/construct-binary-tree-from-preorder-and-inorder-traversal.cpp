// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
	TreeNode *buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		return this->buildTree(0, 0, preorder.size(), preorder, inorder);
	}
private:
	TreeNode *buildTree(const size_t& i, const size_t& j, const size_t& n, const vector<int>& preorder, const vector<int>& inorder) {
		if (n == 0) return NULL;
		TreeNode *root = new TreeNode(preorder[i]);
		size_t k = j;
		for (k = j; k < j + n && inorder[k] != root->val; ++k);
		root->left = this->buildTree(i + 1, j, k - j, preorder, inorder);
		root->right = this->buildTree(i + k - j + 1, k + 1, n - k + j - 1, preorder, inorder);
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
	vector<int> preorder = {7,10,4,3,1,2,8,11};
	vector<int> inorder = {4,10,3,1,7,11,8,2};
	TreeNode *root = solution.buildTree(preorder, inorder);
	inorderTraversal(root);
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}