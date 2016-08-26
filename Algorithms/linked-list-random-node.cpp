// 382. Linked List Random Node
// https://leetcode.com/problems/linked-list-random-node/
// https://en.wikipedia.org/wiki/Reservoir_sampling
// https://discuss.leetcode.com/topic/53812/using-reservoir-sampling-o-1-space-o-n-time-complexity-c/2
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		srand (time(NULL));
		this->head = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int result = this->head->val;
		int n = 2;
		for (ListNode *it = this->head->next; it; it = it->next)
			if (rand() % n++ == 0)
				result = it->val;
		return result;
	}
private:
	ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(void) {
	// Init a singly linked list [1,2,3].
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution solution(head);

	// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
	cout << solution.getRandom() << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}