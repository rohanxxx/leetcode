# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, forward, curr = None, None, head
        
        #forward = None
        while curr != None:
            forward = curr.next
            curr.next = prev
            prev = curr
            curr = forward

        return prev
            
        