//206. Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/
//https://leetcode.com/discuss/34474/in-place-iterative-and-recursive-java-solution

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(const int& x) : val(x), next(0) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* newHead = 0;
		while (head) {
			ListNode* next = head->next;
			head->next = newHead;
			newHead = head;
			head = next;
		}
		return newHead;
	}
};

int main(int argc, char** argv) {
	Solution solution;
	ListNode* head = new ListNode(0);
	ListNode* it = head;
	for (int i = 1; i <= 10; ++i) {
		it->next = new ListNode(i);
		it = it->next;
	}
	ListNode* newHead = solution.reverseList(head);
	it = newHead;
	while (it) {
		cout << it->val << '\n';
		it = it->next;
	}
	getchar();
	return 0;
}
