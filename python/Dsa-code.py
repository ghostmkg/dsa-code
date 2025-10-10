# I Make Change In Code In Easy Ways

# 1. Code ( link list _Sum.py )

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def sum_linked_list(head):
    total = 0
    while head:
        total += head.data
        head = head.next
    return total

# Example
head = Node(5)
head.next = Node(10)
head.next.next = Node(15)
print("Linked List Sum:", sum_linked_list(head))


# 2. Code ( half- linklist.py )

def print_half(head):
    slow, fast = head, head
    while fast and fast.next:
        print(slow.data, end=" -> ")
        slow, fast = slow.next, fast.next.next
    print("END")

# Example
head = Node(1); head.next = Node(2); head.next.next = Node(3)
head.next.next.next = Node(4); head.next.next.next.next = Node(5)
print_half(head)  # prints 1 -> 2 -> END


# 3. Code ( helloWorld.py )

def hello_world():
    codes = [72,101,108,108,111,32,87,111,114,108,100]
    return "".join(chr(c) for c in codes)

print(hello_world())


# 4. Code ( Sum of 1d arrays.py )

def sum_array(arr):
    total = 0
    for num in arr:
        total += num
    return total

arr = [1,2,3,4,5]
print("Array Sum:", sum_array(arr))
