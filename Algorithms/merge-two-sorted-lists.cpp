// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
// https://github.com/soulmachine/leetcode
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(INT_MIN);
		for (ListNode *it = dummy; l1 || l2; it = it->next) {
			int val1 = l1 ? l1->val : INT_MAX;
			int val2 = l2 ? l2->val : INT_MAX;
			if (val1 < val2) {
				it->next = l1;
				l1 = l1->next;
			}
			else {
				it->next = l2;
				l2 = l2->next;
			}
		}
		return dummy->next;
	}
};