// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
// https://en.wikipedia.org/wiki/Cycle_detection
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head || !head->next) return false;
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = head->next->next->next;
	cout << boolalpha << solution.hasCycle(head) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}