/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while(l1 && l2){
            int digit = l1->val + l2->val;
            curr->next = new ListNode((digit + carry) % 10);
            curr = curr->next;
            carry = (digit + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* l = l1 ? l1 : l2;

        while(l){
            curr->next = new ListNode((l->val + carry) % 10);
            curr = curr->next;
            carry = (l->val + carry) / 10;
            l = l->next;
        }

        if(carry){
            curr->next = new ListNode(carry);
        }

        return dummy.next;



    }
};
