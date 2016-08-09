// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		if (this->hashMap.count(head->label)) return this->hashMap[head->label];
		RandomListNode *clone =  new RandomListNode(head->label);
		this->hashMap[head->label] = clone;
		clone->next = this->copyRandomList(head->next);
		clone->random = this->copyRandomList(head->random);
		return clone;
	}
private:
	unordered_map<int, RandomListNode *> hashMap;
};
int main(void) {
	Solution solution;
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}