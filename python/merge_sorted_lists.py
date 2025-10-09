class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_two_lists(l1, l2):
    """
    Merge two sorted linked lists into one sorted list.
    
    Time: O(n + m), Space: O(1)
    """
    dummy = ListNode(0)
    current = dummy
    
    while l1 and l2:
        if l1.val <= l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next
    
    # Attach remaining nodes
    current.next = l1 if l1 else l2
    
    return dummy.next

# Helper function to print list
def print_list(head):
    values = []
    while head:
        values.append(head.val)
        head = head.next
    print(values)

# Example usage
l1 = ListNode(1, ListNode(2, ListNode(4)))
l2 = ListNode(1, ListNode(3, ListNode(4)))
merged = merge_two_lists(l1, l2)
print_list(merged)  # Output: [1, 1, 2, 3, 4, 4]