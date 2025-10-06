sumhead = [1,2,3,4,5,6]

def middleLinkList(head):
    temp = head
    count = 0
    while temp:
        count += 1
        temp = temp.next
    cur = count // 2
    leng = 0
    while head is not None:
        if cur == leng:
            return head  
        leng += 1
        head = head.next
    
print(middleLinkList(head))
