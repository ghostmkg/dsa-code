import heapq

class MinHeap:
    """
    Min Heap implementation using Python's heapq
    """
    
    def __init__(self):
        self.heap = []
    
    def push(self, val):
        """Add an element to the heap"""
        heapq.heappush(self.heap, val)
    
    def pop(self):
        """Remove and return the smallest element"""
        if not self.heap:
            raise IndexError("pop from empty heap")
        return heapq.heappop(self.heap)
    
    def peek(self):
        """Return the smallest element without removing it"""
        if not self.heap:
            raise IndexError("peek from empty heap")
        return self.heap[0]
    
    def size(self):
        """Return the number of elements in the heap"""
        return len(self.heap)
    
    def is_empty(self):
        """Check if the heap is empty"""
        return len(self.heap) == 0
    
    def heapify(self, arr):
        """Convert an array into a heap"""
        self.heap = arr.copy()
        heapq.heapify(self.heap)

class MaxHeap:
    """
    Max Heap implementation (using min heap with negated values)
    """
    
    def __init__(self):
        self.heap = []
    
    def push(self, val):
        """Add an element to the heap"""
        heapq.heappush(self.heap, -val)
    
    def pop(self):
        """Remove and return the largest element"""
        if not self.heap:
            raise IndexError("pop from empty heap")
        return -heapq.heappop(self.heap)
    
    def peek(self):
        """Return the largest element without removing it"""
        if not self.heap:
            raise IndexError("peek from empty heap")
        return -self.heap[0]
    
    def size(self):
        """Return the number of elements in the heap"""
        return len(self.heap)
    
    def is_empty(self):
        """Check if the heap is empty"""
        return len(self.heap) == 0

def heap_sort(arr):
    """
    Heap sort algorithm implementation
    Time Complexity: O(n log n)
    Space Complexity: O(1)
    """
    # Build max heap
    n = len(arr)
    
    # Heapify the array (build max heap from bottom up)
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(arr, n, i)
    
    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        # Move current root to end
        arr[0], arr[i] = arr[i], arr[0]
        
        # Call heapify on the reduced heap
        max_heapify(arr, i, 0)
    
    return arr

def max_heapify(arr, n, i):
    """
    Maintain max heap property
    """
    largest = i  # Initialize largest as root
    left = 2 * i + 1  # Left child
    right = 2 * i + 2  # Right child
    
    # If left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    # If right child exists and is greater than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        
        # Recursively heapify the affected sub-tree
        max_heapify(arr, n, largest)

def find_kth_largest(nums, k):
    """
    Find kth largest element using min heap
    Time Complexity: O(n log k)
    Space Complexity: O(k)
    """
    heap = []
    
    for num in nums:
        if len(heap) < k:
            heapq.heappush(heap, num)
        elif num > heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, num)
    
    return heap[0]

def find_kth_smallest(nums, k):
    """
    Find kth smallest element using max heap
    Time Complexity: O(n log k)
    Space Complexity: O(k)
    """
    heap = []
    
    for num in nums:
        if len(heap) < k:
            heapq.heappush(heap, -num)  # Use negative for max heap
        elif num < -heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, -num)
    
    return -heap[0]

def merge_k_sorted_arrays(arrays):
    """
    Merge k sorted arrays using min heap
    Time Complexity: O(n log k) where n is total elements
    Space Complexity: O(k)
    """
    heap = []
    result = []
    
    # Initialize heap with first element from each array
    for i, arr in enumerate(arrays):
        if arr:  # Check if array is not empty
            heapq.heappush(heap, (arr[0], i, 0))  # (value, array_index, element_index)
    
    while heap:
        val, arr_idx, elem_idx = heapq.heappop(heap)
        result.append(val)
        
        # Add next element from the same array
        if elem_idx + 1 < len(arrays[arr_idx]):
            next_val = arrays[arr_idx][elem_idx + 1]
            heapq.heappush(heap, (next_val, arr_idx, elem_idx + 1))
    
    return result

# Test the heap implementations
if __name__ == "__main__":
    # Test Min Heap
    print("=== Min Heap Test ===")
    min_heap = MinHeap()
    values = [20, 15, 30, 10, 5, 7, 6, 12]
    
    print(f"Adding values: {values}")
    for val in values:
        min_heap.push(val)
    
    print("Extracting all elements from min heap:")
    while not min_heap.is_empty():
        print(min_heap.pop(), end=" ")
    print()
    
    # Test Max Heap
    print("\n=== Max Heap Test ===")
    max_heap = MaxHeap()
    
    print(f"Adding values: {values}")
    for val in values:
        max_heap.push(val)
    
    print("Extracting all elements from max heap:")
    while not max_heap.is_empty():
        print(max_heap.pop(), end=" ")
    print()
    
    # Test Heap Sort
    print("\n=== Heap Sort Test ===")
    unsorted_array = [64, 34, 25, 12, 22, 11, 90]
    print(f"Original array: {unsorted_array}")
    sorted_array = heap_sort(unsorted_array.copy())
    print(f"Heap sorted array: {sorted_array}")
    
    # Test kth largest/smallest
    print("\n=== Kth Element Tests ===")
    test_nums = [3, 2, 1, 5, 6, 4]
    k = 2
    print(f"Array: {test_nums}")
    print(f"{k}nd largest element: {find_kth_largest(test_nums, k)}")
    print(f"{k}nd smallest element: {find_kth_smallest(test_nums, k)}")
    
    # Test merge k sorted arrays
    print("\n=== Merge K Sorted Arrays Test ===")
    sorted_arrays = [
        [1, 4, 5],
        [1, 3, 4],
        [2, 6]
    ]
    print(f"Input arrays: {sorted_arrays}")
    merged = merge_k_sorted_arrays(sorted_arrays)
    print(f"Merged array: {merged}")