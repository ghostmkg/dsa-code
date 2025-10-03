# Problem: Reverse a singly linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head: ListNode):
    prev, curr = None, head
    while curr:
        nxt = curr.next
        curr.next = prev
        prev, curr = curr, nxt
    return prev

# Input: 1 -> 2 -> 3 -> None
# Output: 3 -> 2 -> 1 -> None
