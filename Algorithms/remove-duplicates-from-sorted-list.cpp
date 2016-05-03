// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(const int& x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        ListNode* it(head);
        while (it) {
            it->next = this->next(it);
            it = it->next;
        }
        return head;
    }
private:
    ListNode* next(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;
        if (head->val != head->next->val) return head->next;
        ListNode* it(head);
        while(it && head->val == it->val) {
            it = it->next;
        }
        return it;
    }
};
int main(int argc, char** argv) {
	Solution solution;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);
	for (ListNode* it = solution.deleteDuplicates(head); it; it = it->next) {
		cout << it->val << '\t';
	}
	cout << '\n';
	return 0;
}
