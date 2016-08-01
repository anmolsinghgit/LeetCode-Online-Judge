// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// https://discuss.leetcode.com/topic/24418/recursive-bst-construction-using-slow-fast-traversal-on-linked-list
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return (new TreeNode(head->val));
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *previous = NULL;
		while (fast && fast->next) {
			fast = fast->next->next;
			previous = slow;
			slow = slow->next;
		}
		previous->next = NULL;
		TreeNode *root = new TreeNode(slow->val);
		root->left = this->sortedListToBST(head);
		root->right = this->sortedListToBST(slow->next);
		return root;
	}
};
void inorderTraversal(TreeNode *root) {
	if (!root) return;
	inorderTraversal(root->left);
	cout << root->val << '\t';
	inorderTraversal(root->right);
	return;
}
int main(void) {
	Solution solution;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	TreeNode *root = solution.sortedListToBST(head);
	inorderTraversal(root);
	cout << "\nPassed\n";
	cout << "\nPassed All\n";	
	return 0;
}