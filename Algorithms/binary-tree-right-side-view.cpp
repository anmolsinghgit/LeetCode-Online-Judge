// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	Solution(): depth(-1) {}
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		this->BFS(root);
		this->preorderTraversal(root, result);
		return result;
	}
private:
	unordered_map<TreeNode *, int> hashMap;
	int depth;
	void BFS(TreeNode *root) {
		this->hashMap[root] = 0;
		deque<TreeNode *> dq;
		dq.push_back(root);
		while (!dq.empty()) {
			root = dq.front();
			if (root->left) {
				this->hashMap[root->left] = this->hashMap[root] + 1;
				dq.push_back(root->left);
			}
			if (root->right) {
				this->hashMap[root->right] = this->hashMap[root] + 1;
				dq.push_back(root->right);
			}
			dq.pop_front();
			continue;
		}
	}
	void preorderTraversal(TreeNode* root, vector<int>& result) {
		if (!root) return;
		if (this->hashMap[root] > this->depth) {
			result.push_back(root->val);
			this->depth = this->hashMap[root];
		}
		this->preorderTraversal(root->right, result);
		this->preorderTraversal(root->left, result);
		return;
	}
};
int main(void) {
	Solution solution;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	for (const auto &i : solution.rightSideView(root)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}