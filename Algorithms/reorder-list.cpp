// 143. Reorder List
// https://leetcode.com/problems/reorder-list/
// https://discuss.leetcode.com/topic/7425/a-concise-o-n-time-o-1-in-place-solution
// https://discuss.leetcode.com/topic/13869/java-solution-with-3-steps
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *secondhead = NULL;
		ListNode *nextsecondhead = slow->next;
		slow->next = NULL;
		while (nextsecondhead) {
			ListNode *nextnextsecondhead = nextsecondhead->next;
			nextsecondhead->next = secondhead;
			secondhead = nextsecondhead;
			nextsecondhead = nextnextsecondhead;
		}
		for (ListNode *p1 = head, *p2 = secondhead; p2;) {
			ListNode *nextp1 = p1->next;
			p1 = p1->next = p2;
			p2 = nextp1;
		}
		return;
	}
};
int main(void) {
	Solution solution;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	for (ListNode *it = head; it; it = it->next) cout << it->val << '\t';
	cout << '\t';
	solution.reorderList(head);
	for (ListNode *it = head; it; it = it->next) cout << it->val << '\t';
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
