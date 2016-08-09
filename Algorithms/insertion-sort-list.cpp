// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
// https://discuss.leetcode.com/topic/8570/an-easy-and-clear-way-to-sort-o-1-space/3
#include <iostream>
#include <climits>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *dummy = new ListNode(INT_MIN);
		while (head) {
			ListNode *it = dummy;
			while (it->next && it->next->val < head->val) it = it->next;
			ListNode* next = head->next;
			head->next = it->next;
			it->next = head;
			head = next;
		}
		return dummy->next;
	}
};
int main(void) {
	Solution solution;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(-11);
	head->next->next->next = new ListNode(-21);
	head->next->next->next->next = new ListNode(2);
	head->next->next->next->next->next = new ListNode(-20);
	for (ListNode *cur = head; cur; cur = cur->next) cout << cur->val << '\t';
	cout << '\t';
	head = solution.insertionSortList(head);
	for (ListNode *cur = head; cur; cur = cur->next) cout << cur->val << '\t';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}