class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def constructLL(self, arr):
        # code here
        head = Node(arr[0])
        
        curr = head
        
        for i in range(1,len(arr)):
            curr.next = Node(arr[i])
            curr = curr.next
        return head

def printList(head):
    curr = head
    while curr:
        print(curr.data, end=" -> ")
        curr = curr.next
    print("None")


# Driver code
if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    obj = Solution()
    head = obj.constructLL(arr)

    print("Linked List constructed from array:")
    printList(head)