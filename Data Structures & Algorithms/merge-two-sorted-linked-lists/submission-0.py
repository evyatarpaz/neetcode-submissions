# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1

        head = None
        curr = None
        while list1 and list2:
            if not head:
                if list1.val <= list2.val:
                    head = ListNode(list1.val)
                    curr = head
                    list1 = list1.next
                else:
                    head = ListNode(list2.val)
                    curr = head
                    list2 = list2.next
            else:
                if list1.val <= list2.val:
                    head.next = ListNode(list1.val)
                    head = head.next
                    list1 = list1.next
                else:
                    head.next = ListNode(list2.val)
                    head = head.next
                    list2 = list2.next
        
        if list1:
            head.next = list1

        if list2:
            head.next = list2

        return curr


