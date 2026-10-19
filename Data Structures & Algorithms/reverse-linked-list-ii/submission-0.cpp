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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = dummy;
        ListNode* prevStart = nullptr;
        int diff = right - left;
        while(left--){
            prevStart = start;
            start = start->next;
        }
        ListNode* end = start;
        while(diff--){
            end = end->next;
        }
        ListNode* endNext = end->next;
        end->next = nullptr;
        reverseList(start);
        start->next = endNext;
        prevStart->next = end;
        return dummy->next;

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