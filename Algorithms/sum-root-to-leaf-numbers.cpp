// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// https://discuss.leetcode.com/topic/6731/short-java-solution-recursion/2
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		return this->sumNumbers(root, 0);
	}
private:
	int sumNumbers(TreeNode *root, const int& sum) {
		if (!root) return 0;
		if (!root->left && !root->right) return 10 * sum + root->val;
		return this->sumNumbers(root->left, 10 * sum + root->val) + this->sumNumbers(root->right, 10 * sum + root->val);
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	if (solution.sumNumbers(root) == 25) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}