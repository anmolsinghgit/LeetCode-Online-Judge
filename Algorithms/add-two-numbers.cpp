/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_len = length(l1);
        int l2_len = length(l2);
        int ret_len = max(l1_len, l2_len);
        ListNode* ret_head = initialize_list(ret_len);
        plus_list(ret_head, l1, l2);
        update_list(ret_head);
        return ret_head;
    }
private:
    int length(ListNode* l){
        int len = 0;
        ListNode* itr = l;
        while(itr){
            ++len;
            itr = itr->next;
        }
        return len;
    }
private:
    ListNode* initialize_list(int len){
    	ListNode* head = NULL;
        if(len < 1){
            exit(0);
        }
    	else if(len >= 1){
            int l = 0;
            head = new ListNode(0);
            ListNode* itr = head;
            while(l < len - 1){
                itr->next = new ListNode(0);
                itr = itr->next;
                ++l;
            }
        }
    return head;
    }
private:
    void plus_list(ListNode* ret_head, ListNode* l1, ListNode* l2){
        ListNode* l1_itr = l1;
        ListNode* l2_itr = l2;
        ListNode* ret_head_itr = ret_head;
        while(ret_head_itr){
            if(l1_itr && l2_itr){
                ret_head_itr->val = l1_itr->val + l2_itr->val;
                l1_itr = l1_itr->next;
                l2_itr = l2_itr->next;   
            }
            else if(l1_itr && !l2_itr){
                ret_head_itr->val = l1_itr->val;
                l1_itr = l1_itr->next;   
            }
            else if(!l1_itr && l2_itr){
                ret_head_itr->val = l2_itr->val;
                l2_itr = l2_itr->next;   
            }
            ret_head_itr = ret_head_itr->next;
        }
    }
private:
    void update_list(ListNode* ret_head){
        ListNode* itr = ret_head;
        while(itr){
            if(itr->val >= 10 && itr->next){
                itr->val -= 10;
                itr->next->val += 1;   
            }
            else if(itr->val >= 10 && !itr->next){
                itr->next = new ListNode(0);
                itr->val -= 10;
                itr->next->val += 1;                
            }
            itr = itr->next;
        }
    }
};
