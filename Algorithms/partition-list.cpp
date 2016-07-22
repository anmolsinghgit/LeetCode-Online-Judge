// 86. Partition List
// https://leetcode.com/problems/partition-list/
// https://siddontang.gitbooks.io/leetcode-solution/content/linked_list/partition_list.html
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(const int& x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, const int& x) {
		ListNode dummy1(-1);
		ListNode dummy2(-1);
		ListNode *less = &dummy1;
		ListNode *noless = &dummy2;
		for (ListNode *it = head; it; it = it->next) {
			if (it->val < x) {
				less->next = it;
				less = less->next;
			}
			else {
				noless->next = it;
				noless = noless->next;
			}
		}
		less->next = dummy2.next;
		noless->next = NULL;
		return dummy1.next;
	}
};
int main(void) {
	Solution solution;
	vector<int> input = {1, 4, 3, 2, 5, 2};
	ListNode *head = new ListNode(input[0]);
	ListNode *it = head;
	for (size_t i = 1; i < input.size(); ++i) {
		it->next = new ListNode(input[i]);
		it = it->next;
	}
	for (ListNode *it = solution.partition(head, 3); it; it = it->next) {
		cout << it->val << '\t';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}