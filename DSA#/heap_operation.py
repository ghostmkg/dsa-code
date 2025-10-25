class Heap:
    def __init__(self):
        self.heap = []

    def createHeap(self, c):
        for e in c:
            self.insert(e)

    def insert(self, e):
        self.heap.append(e)
        
        index = len(self.heap) - 1
        parent = (index - 1) // 2
        
        while index > 0 and self.heap[parent] < self.heap[index]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            index = parent
            parent = (index - 1) // 2
        
    def top(self):
        if not self.heap:
            return None
        return self.heap[0]

    def delete(self):
        if len(self.heap) == 0:
            print("Empty")
            return None
            
        if len(self.heap) == 1:
            return self.heap.pop()
            
        maxm = self.heap[0]
        self.heap[0] = self.heap.pop()
        
        index = 0
        
        while True:
            left_child_index = (2 * index) + 1
            right_child_index = (2 * index) + 2
            largest = index
            
            if left_child_index < len(self.heap) and self.heap[left_child_index] > self.heap[largest]:
                largest = left_child_index
                
            if right_child_index < len(self.heap) and self.heap[right_child_index] > self.heap[largest]:
                largest = right_child_index
                
            if largest != index:
                self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
                index = largest
            else:
                break
                
        return maxm