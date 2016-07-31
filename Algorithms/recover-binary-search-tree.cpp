// 99. Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/
// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
// http://www.lifeincode.net/programming/leetcode-recover-binary-search-tree-java/
// http://www.cnblogs.com/yuzhangcmu/p/4208319.html
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(const int& x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void recoverTree(TreeNode* root) {
		if (!root) return;
		TreeNode *current = root;
		TreeNode *previous = NULL;
		TreeNode *predecessor = NULL;
		while (current) {
			if (!current->left) {
				this->search(previous, current);
				previous = current;
				current = current->right;
			} else {
				predecessor = current->left;
				while (predecessor->right && predecessor->right != current) predecessor = predecessor->right;
				if (!predecessor->right) {
					this->search(previous, current);
					predecessor->right = current;
					current = current->left;
				} else {
					this->search(previous, current);
					predecessor->right = NULL;
					previous = current;
					current = current->right;
				}
			}
		}
		swap(first->val, second->val);
		return;
	}
private:
	TreeNode *first = NULL;
	TreeNode *second = NULL;
	void search(TreeNode *previous, TreeNode *current) {
		if (previous && current && previous->val >= current->val) {
			if (!first) first = previous;
			second = current; 
		}
		return;
	}
};
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	if (!root) return result;
	vector<int> v = inorderTraversal(root->left);
	result.insert(end(result), begin(v), end(v));
	result.push_back(root->val);
	v = inorderTraversal(root->right);
	result.insert(end(result), begin(v), end(v));
	return result;
}
int main(void) {
	Solution solution;
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	solution.recoverTree(root);
	vector<int> v = inorderTraversal(root);
	if (is_sorted(begin(v), end(v))) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}