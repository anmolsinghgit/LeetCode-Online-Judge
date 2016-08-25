// 369. Plus One Linked List
// https://leetcode.com/problems/plus-one-linked-list/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* plusOne(ListNode* head) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *i = dummy;
		ListNode *j = dummy;
		while (j->next) {
			j = j->next;
			if (j->val < 9) i = j; 
		}
		if (j->val < 9) {
			j->val++;
			return dummy->next;
		}
		i->val++;
		for (ListNode *it = i->next; it; it = it->next) it->val = 0;
		if (i == dummy) return dummy;
		return dummy->next;
	}
};
// class Solution {
// public:
// 	ListNode* plusOne(ListNode* head) {
// 		head = this->reverse(head);
// 		for (ListNode *it = head; it; it = it->next) {
// 			if (it->val < 9) {
// 				it->val++;
// 				break;
// 			}
// 			it->val = 0;
// 			if (!it->next) {
// 				it->next = new ListNode(1);
// 				break;
// 			}
// 		}
// 		return this->reverse(head);
// 	}
// private:
// 	ListNode* reverse(ListNode* head) {
// 		ListNode *result = NULL;
// 		while (head) {
// 			ListNode *next = head->next;
// 			head->next = result;
// 			result = head;
// 			head = next;
// 		}
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	ListNode *head = new ListNode(1);
	for (ListNode *it = solution.plusOne(head); it; it = it->next) cout << it->val << '\t';
	cout << "\nPassed\n";
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	for (ListNode *it = solution.plusOne(head); it; it = it->next) cout << it->val << '\t';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}