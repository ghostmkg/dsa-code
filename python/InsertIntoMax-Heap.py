def insert_into_heap(heap, x):
    heap.append(x)

    i = len(heap)-1

    while i>0:
        parent = (i-1)//2
        if heap[i]>heap[parent]:
            heap[i],heap[parent]=heap[parent],heap[i]
        i = parent
    return heap

heap = [15, 12, 10, 2, 7]
x = 90
print(insert_into_heap(heap,x))