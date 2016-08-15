// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/
// https://discuss.leetcode.com/topic/6575/my-solutions-in-3-languages-with-stack/2
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root) {
			this->stack.push_back(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !this->stack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *topofstack = this->stack.back();
		int result = topofstack->val;
		this->stack.pop_back();
		topofstack = topofstack->right;
		while (topofstack) {
			this->stack.push_back(topofstack);
			topofstack = topofstack->left;
		}
		return result;
	}
private:
	vector<TreeNode *>stack;
};
int main(void) {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) cout << i.next();
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */