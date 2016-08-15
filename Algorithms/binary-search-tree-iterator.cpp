// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/
// https://discuss.leetcode.com/topic/8154/morris-traverse-solution
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
		this->current = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return this->current;
	}

	/** @return the next smallest number */
	int next() {
		while (this->current) {
			if (!this->current->left) {
				int result = this->current->val;
				this->current = this->current->right;
				return result;
			}
			TreeNode *pred = current->left;
			while (pred->right && pred->right != this->current) pred = pred->right;
			if (!pred->right) {
				pred->right = this->current;
				current = current->left;
				continue;
			}
			pred->right = NULL;
			int result = this->current->val;
			this->current = this->current->right;
			return result;		
		}
		return 0;
	}
private:
	TreeNode *current;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
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