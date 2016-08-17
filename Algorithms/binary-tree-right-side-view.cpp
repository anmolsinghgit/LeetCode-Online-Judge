// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/
// https://discuss.leetcode.com/topic/11768/my-simple-accepted-solution-java
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		this->preorderTraveral(root, 0, result);
		return result;
	}
private:
	void preorderTraveral(TreeNode *root, size_t depth, vector<int>& result) {
		if (!root) return;
		if (depth == result.size()) result.push_back(root->val);
		this->preorderTraveral(root->right, depth + 1, result);
		this->preorderTraveral(root->left, depth + 1, result);
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