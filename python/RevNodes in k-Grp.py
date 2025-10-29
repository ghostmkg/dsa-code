# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Helper function to get the kth node from current
        def getKth(curr, k):
            while curr and k > 0:
                curr = curr.next
                k -= 1
            return curr

        dummy = ListNode(0, head)
        groupPrev = dummy

        while True:
            # Find the kth node from current position
            kth = getKth(groupPrev, k)
            if not kth:
                break  # not enough nodes left
            
            groupNext = kth.next

            # Reverse the group
            prev, curr = kth.next, groupPrev.next
            while curr != groupNext:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp

            # Connect with the previous part
            tmp = groupPrev.next
            groupPrev.next = kth
            groupPrev = tmp

        return dummy.next
