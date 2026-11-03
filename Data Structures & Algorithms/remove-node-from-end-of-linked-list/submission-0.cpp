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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;

        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* prevN = &dummy;
        ListNode* cur = head;
        while(n && cur){
            n--;
            cur = cur->next;
        }
        if(n != 0) return head;

        ListNode* nodeN = head;
        while(cur){
            prevN = nodeN;
            nodeN = nodeN->next;
            cur = cur->next;
        }
        
        prevN->next = nodeN->next;
        delete nodeN;
        return dummy.next;
        
    }
};
