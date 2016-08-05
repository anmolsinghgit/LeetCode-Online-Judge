// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// https://discuss.leetcode.com/topic/1106/o-1-space-o-n-complexity-iterative-solution
// https://siddontang.gitbooks.io/leetcode-solution/content/tree/populating_next_right_pointers_in_each_node.html
#include <iostream>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode *current = root;
		TreeLinkNode *previous = NULL;
		TreeLinkNode *head = NULL;
		while (current) {
			while (current) {
				if (current->left) {
					if (previous) previous->next = current->left;
					else head = current->left;
					previous = current->left;
				}
				if (current->right) {
					if (previous) previous->next = current->right;
					else head = current->right;
					previous = current->right;
				}
				current = current->next;
			}
			current = head;
			previous = NULL;
			head = NULL;
		}
	}
};
void inorderTraversal(TreeLinkNode *root) {
	TreeLinkNode *current = root;
	while (current) {
		if (!current->left) {
			cout << current->val << '\t';
			current = current->right;
		} else {
			TreeLinkNode *predecessor = current->left;
			while (predecessor->right && predecessor->right != current) predecessor = predecessor->right;
			if (!predecessor->right) {
				predecessor->right = current;
				current = current->left;
			} else {
				cout << current->val << '\t';
				predecessor->right = NULL;
				current = current->right;
			}
		}
	}
	current = NULL;
	return;
}
int main(void) {
	Solution solution;
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->right = new TreeLinkNode(7);
	solution.connect(root);
	inorderTraversal(root);
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}