// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		TreeNode *dump = new TreeNode(0);
		dump->left = root;
		while (dump) {
			if (!dump->left) {
				dump = dump->right;
				continue;
			}
			TreeNode *predecessor = dump->left;
			while (predecessor->right && predecessor->right != dump) predecessor = predecessor->right;
			if (!predecessor->right) {
				predecessor->right = dump;
				dump = dump->left;
				continue;
			}
			this->reverseOut(dump->left, predecessor, result);
			predecessor->right = NULL;
			dump = dump->right;
		}
		return result;
	}
private:
	void reverse(TreeNode* begin, TreeNode* end) {
		TreeNode* i = begin->right;
		while (begin != end) {
			TreeNode *j = i->right;
			i->right = begin;
			begin = i;
			i = j;
		}
	}
	void reverseOut(TreeNode* begin, TreeNode* end, vector<int>& result) {
		this->reverse(begin, end);
		for (TreeNode *it = end; it != begin; it = it->right) result.push_back(it->val);
		result.push_back(begin->val);
		this->reverse(end, begin);
	}
};
// class Solution {
// public:
// 	vector<int> postorderTraversal(TreeNode* root) {
// 		vector<int> result;
// 		this->postorderTraversal(root, result);
// 		return result;
// 	}
// private:
// 	void postorderTraversal(TreeNode* root, vector<int>& result) {
// 		if (!root) return;
// 		this->postorderTraversal(root->left, result);
// 		this->postorderTraversal(root->right, result);
// 		result.push_back(root->val);
// 	}
// };
// class Solution {
// public:
// 	vector<int> postorderTraversal(TreeNode* root) {
// 		if (!root) return {};
// 		vector<int> leftSubtree =  this->postorderTraversal(root->left);
// 		vector<int> rightSubtree =  this->postorderTraversal(root->right);
// 		vector<int> result;
// 		result.insert(end(result), begin(leftSubtree), end(leftSubtree));
// 		result.insert(end(result), begin(rightSubtree), end(rightSubtree));
// 		result.push_back(root->val);
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left =  new TreeNode(3);
	for (const auto &i : solution.postorderTraversal(root)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}