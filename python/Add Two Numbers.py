# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        t = l1

        x = 0
        y = 0
        i = 0

        #* Convert to integer
        while t != None:
            
            x += t.val * (10**i)

            t = t.next
            i += 1

        t = l2
        i = 0

        #* Convert to integer
        while t != None:
            
            y += t.val * (10**i)

            t = t.next
            i += 1

        ans = x + y
        __res = ListNode()
        res = __res

        #* Reverse the answer and store in a linked list.
        while (ans > 0):

            tmp = ListNode()
            __res.val = ans % 10
            ans = ans // 10

            if ans > 0:
                __res.next = tmp
                __res = __res.next

        return res
