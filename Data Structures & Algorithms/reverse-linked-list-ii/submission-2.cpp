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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        // ListNode* start = dummy;
        // ListNode* prevStart = nullptr;
        // int diff = right - left;
        // while(left--){
        //     prevStart = start;
        //     start = start->next;
        // }
        // ListNode* end = start;
        // while(diff--){
        //     end = end->next;
        // }
        // ListNode* endNext = end->next;
        // end->next = nullptr;
        // reverseList(start);
        // start->next = endNext;
        // prevStart->next = end;
        // return dummy->next;
        if(!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for(int i = 0; i<left-1; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        for(int i = 0; i < right - left; i++){
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy.next;

    }

    void reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

    }
};