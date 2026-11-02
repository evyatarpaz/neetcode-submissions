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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy = ListNode();
        ListNode* cur = &dummy;

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>, decltype(cmp)> min_heap(cmp);

        for(auto list: lists){
            if(list != nullptr){
                min_heap.push(list);
            }
        }

        while(!min_heap.empty()){
            ListNode* node = min_heap.top();
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            node = node->next;
            if(node){
                min_heap.push(node);
            }
        }
        return dummy.next;
    }
};
