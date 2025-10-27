# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        #* Ascending order!
        
        tmp_l = []
        t: ListNode = list1

        while t is not None:
            tmp_l.append(t.val)
            t = t.next

        t = list2
        while t is not None:
            tmp_l.append(t.val)
            t = t.next

        tmp_l = sorted(tmp_l)
        
        if tmp_l:
            t = ListNode(tmp_l[0])
            head = t

            for i in range(1,len(tmp_l)):
                t.next = ListNode(tmp_l[i])
                t = t.next

            return head
        
        return None
