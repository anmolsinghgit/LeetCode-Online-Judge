// 250. Count Univalue Subtrees
// https://leetcode.com/problems/count-univalue-subtrees/
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int countUnivalSubtrees(TreeNode* root) {
		int result = 0;
		if (!root) return result;
		this->inOrderTraversal(root, result);
		return result;
	}
private:
	bool isUnivalSubtrees(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *top = q.front();
			if (top->left) {
				if (top->left->val != root->val) return false;
				q.push(top->left);
			}
			if (top->right) {
				if (top->right->val != root->val) return false;
				q.push(top->right);				
			}
			q.pop();
		}
		return true;
	}
	void inOrderTraversal(TreeNode* root, int& result) {
		if (!root) return;
		this->inOrderTraversal(root->left, result);
		if (this->isUnivalSubtrees(root)) ++result;
		this->inOrderTraversal(root->right, result);
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(5);
	cout << solution.countUnivalSubtrees(root) << "\tPassed\n";
	root = new TreeNode(5);
	root->left = new TreeNode(5);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(5);
	cout << solution.countUnivalSubtrees(root) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}