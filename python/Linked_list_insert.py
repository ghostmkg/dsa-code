class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    # Insert at start
    def insert_at_start(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Delete at end
    def delete_at_end(self):
        if self.head is None:
            print("List is empty")
            return

        if self.head.next is None:
            self.head = None
            return

        temp = self.head
        while temp.next.next:   # stop at second-last node
            temp = temp.next
        temp.next = None

    # Display the list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL")


# Example usage
ll = LinkedList()
ll.insert_at_start(10)
ll.insert_at_start(20)
ll.insert_at_start(30)

print("Original Linked List:")
ll.display()

ll.delete_at_end()
print("After deleting at end:")
ll.display()
