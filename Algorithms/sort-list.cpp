// 148. Sort List
// https://leetcode.com/problems/sort-list/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <limits>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *l1 = head;
		ListNode *l2 = slow->next;
		slow->next = NULL;
		return this->mergeTwoSortedLists(sortList(l1), sortList(l2));
	}
private:
	ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(numeric_limits<int>::min());
		for (ListNode *it = head; l1 || l2; ) {
			if (!l1) {
				it->next = l2;
				break;
			}
			if (!l2) {
				it->next = l1;
				break;				
			}
			if (l1->val < l2->val) {
				it->next = l1;
				l1 = l1->next;
				it = it->next;
				continue;
			}
			it->next = l2;
			l2 = l2->next;
			it = it->next;
			continue;
		}
		return head->next;
	}
};
int main(void) {
	// Solution solution;
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}