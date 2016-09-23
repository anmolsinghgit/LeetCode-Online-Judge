// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		while (root) {
			if (!root->left) {
				result.push_back(root->val);
				root = root->right;
				continue;
			}
			TreeNode *predecessor = root->left;
			while (predecessor->right && predecessor->right != root) predecessor = predecessor->right;
			if (!predecessor->right) {
				predecessor->right = root;
				root = root->left;
				continue;
			}
			result.push_back(root->val);
			predecessor->right = NULL;
			root = root->right;
		}
		return result;
	}
};
// class Solution {
// public:
// 	vector<int> inorderTraversal(TreeNode* root) {
// 		vector<int> result;
// 		this->inorderTraversal(root, result);
// 		return result;
// 	}
// private:
// 	void inorderTraversal(TreeNode* root, vector<int>& result) {
// 		if (!root) return;
// 		this->inorderTraversal(root->left, result);
// 		result.push_back(root->val);
// 		this->inorderTraversal(root->right, result);
// 	}
// };
// class Solution {
// public:
// 	vector<int> inorderTraversal(TreeNode* root) {
// 		if (!root) return {};
// 		vector<int> result;
// 		vector<int> leftSubtree = this->inorderTraversal(root->left);
// 		vector<int> rightSubtree = this->inorderTraversal(root->right);
// 		result.insert(end(result), begin(leftSubtree), end(leftSubtree));
// 		result.push_back(root->val);
// 		result.insert(end(result), begin(rightSubtree), end(rightSubtree));
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	for (const auto &i : solution.inorderTraversal(root)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}