// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(const int& x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* it(&dummy);
        while(it) {
            it = this->next(it);
        }
        return dummy.next;
    }
private:
    ListNode* next(ListNode* previous_start) {
        if (previous_start == NULL) 
		return NULL;
        else if (previous_start->next == NULL) 
		return NULL;
	else if (previous_start->next->next == NULL) {
		return previous_start->next;
	}
        ListNode* it(previous_start->next);
        int i(0);
        while (it && it->next && it->next->val == it->val) {
            it = it->next;
            ++i;
        }
	if (i < 1) 
		return it;
	else {
		if (it == NULL)
			previous_start->next = NULL;
		else if (it->next == NULL)
			previous_start->next = NULL;
		else 
			previous_start->next = it->next;
		return previous_start;
	}
    }
};
int main(int argc, char** argv) {
	Solution solution;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(2);
	for (ListNode* it = head; it; it = it->next) {
		cout << it->val << '\t';
	}
	cout << '\n';
	for (ListNode* it = solution.deleteDuplicates(head); it; it = it->next) {
		cout << it->val << '\t';
	}
	cout << '\n';
	return 0;
}
