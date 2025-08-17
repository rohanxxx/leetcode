# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: Optional[ListNode]
        :type x: int
        :rtype: Optional[ListNode]
        """
        before = ListNode(0)
        after = ListNode(0)

        t1, t2 = before, after

        while head:
            nxt = head.next
            head.next = None

            if head.val < x:
                t1.next = head
                t1 = t1.next
            else:
                t2.next = head
                t2 = t2.next

            head = nxt

        t2.next = None
        if after.next:
            t1.next = after.next
        return before.next
        