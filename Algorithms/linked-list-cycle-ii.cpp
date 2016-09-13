// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/
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
	ListNode *detectCycle(ListNode *head) {
		if (!head) return NULL;
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) break;
		}
		if (!fast || !fast->next) return NULL;
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;			
		}
		return slow;
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
	cout << solution.detectCycle(head) << '\t' << head->next->next->next << "\tPassed\n";
	cout << "\nPassed All\n";	
	return 0;
}