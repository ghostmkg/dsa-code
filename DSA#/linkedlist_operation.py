class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
    
class SLL:
    def __init__(self):
        self.head = None
    def printList(self):
        if self.head is None:
            print("Empty List")
        else:
            temp = self.head
            while temp:
                print(temp.val)
                temp = temp.next
    def insertBegin(self):
        val = input()
        nodeBegin = Node(val)
        nodeBegin.next = self.head
        self.head = nodeBegin
    def deleteBegin(self):
        temp = self.head
        self.head=temp.next
        temp=None
    def insertPos(self):
        pos=int(input())
        val=input()
        np=Node(val)
        temp=self.head.next
        prev=self.head
        for i in range(pos-1):
            temp=temp.next
            prev=prev.next
        prev.next=np
        np.next=temp
    def deletePos(self):
        pos=int(input())
        temp=self.head.next
        prev=self.head
        for i in range(1,pos-1):
            temp=temp.next
            prev=prev.next
        prev.next=temp.next
        temp.next=None
    def insertEnd(self):
        val=input()
        ne=Node(val)
        temp=self.head
        while temp.next:
            temp=temp.next
        temp.next=ne
    def deleteEnd(self):
        temp=self.head.next
        prev=self.head
        while temp.next:
            temp=temp.next
            prev=prev.next
        prev.next=None


obj = SLL()
obj.insertBegin()
obj.insertBegin()
obj.insertBegin()
obj.deleteEnd()
obj.printList()