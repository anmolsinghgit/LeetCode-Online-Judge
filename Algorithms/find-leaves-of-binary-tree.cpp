// 366. Find Leaves of Binary Tree
// https://leetcode.com/problems/find-leaves-of-binary-tree/
#include <iostream>
#include <vector>
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
	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> result;
		while (root) result.push_back(this->dfs(root));
		return result;
	}
private:
	vector<int> dfs(TreeNode* &root) {
		vector<int> result;
		if (!root) return result;
		if (!root->left && !root->right) {
			result = {root->val};
			// delete root;
			root = NULL;
			return result;
		}
		vector<int> l = this->dfs(root->left);
		vector<int> r = this->dfs(root->right);
		result.insert(end(result), begin(l), end(l));
		result.insert(end(result), begin(r), end(r));
		return result;
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	for (const auto &i : solution.findLeaves(root)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}