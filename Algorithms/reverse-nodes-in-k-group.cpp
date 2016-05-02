// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(const int& x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, const int& k) {
		if (k <= 1 || head == NULL || head->next == NULL) return head;
		int length = this->length(head);
		if (length < k) return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* tail = this->reverse(&dummy, k);
		while(tail) {
			tail = this->reverse(tail, k);
		}
		return dummy.next;
	}
private:
	int length(ListNode* head) {
		int result(0);
		ListNode* it(head);
		while(it) {
			++result;
			it = it->next;
		}
		return result;
	}
private:
	ListNode* reverse(ListNode* previous_start, const int& k) {
		if (this->length(previous_start->next) < k) return NULL;
		ListNode* previous = previous_start;
		ListNode* current = previous->next;
		ListNode* tail = previous_start->next;
		for (int i = 0; i < k; ++i) {
			ListNode* next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		previous_start->next->next = current;
		previous_start->next = previous;
		return tail;
	}
};
int main(int argc, char** argv) {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution solution;
	
	return 0;
}
