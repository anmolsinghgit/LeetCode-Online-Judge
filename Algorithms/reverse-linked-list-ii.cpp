//92. Reverse Linked List II
//https ://leetcode.com/problems/reverse-linked-list-ii/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(const int& x) : val(x), next(0) {}
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, const int& m, const int& n) {
		if (!head || !head->next || m == n) return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode* previous_start(&dummy);
		for (int i = 0; i < m - 1; ++i) {
			previous_start = previous_start->next;
		}
		//ListNode* next_end(&dummy);
		//for (int i = 0; i < n + 1; ++i) {
		//	next_end = next_end->next;
		//}
		ListNode* previous = previous_start->next;
		ListNode* current = previous->next;
		ListNode* next = current->next;
		for (int i = 0; i < n - m; ++i) {
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		ListNode* next_end = current;
		previous_start->next->next = next_end;
		previous_start->next = previous;
		return dummy.next;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	ListNode* head = new ListNode(1);
	//head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	for (ListNode* it = solution.reverseBetween(head, 1, 1); it; it = it->next) {
		cout << it->val << '\t';
	}
	cout << '\n';
	cout << "Passed\n";
	getchar();
	return 0;
}
