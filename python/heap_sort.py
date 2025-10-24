# Heap Sort Algorithm
# Time Complexity: O(n log n) in all cases
# Space Complexity: O(1) - in-place sorting
# Unstable sorting algorithm

def heapify(arr, n, i):
    """
    Heapify a subtree rooted with node i which is an index in arr.
    n is size of heap.
    """
    largest = i  # Initialize largest as root
    left = 2 * i + 1  # left child
    right = 2 * i + 2  # right child
    
    # If left child is larger than root
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    # If right child is larger than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # swap
        heapify(arr, n, largest)  # recursively heapify the affected sub-tree

def heap_sort(arr):
    """
    Main function to perform heap sort.
    """
    n = len(arr)
    
    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    
    # Extract elements from heap one by one
    for i in range(n - 1, 0, -1):
        # Move current root to end
        arr[0], arr[i] = arr[0], arr[i]
        
        # Call max heapify on the reduced heap
        heapify(arr, i, 0)

def heap_sort_with_steps(arr):
    """
    Heap sort with step-by-step visualization.
    """
    print(f"Original array: {arr}")
    n = len(arr)
    
    # Build max heap
    print("\nBuilding max heap:")
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
        print(f"After heapifying index {i}: {arr}")
    
    # Extract elements
    print("\nExtracting elements:")
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[0], arr[i]
        print(f"After swapping root with index {i}: {arr}")
        heapify(arr, i, 0)
        print(f"After heapifying: {arr}")
    
    return arr

# Example usage
if __name__ == "__main__":
    # Test case 1
    arr1 = [64, 34, 25, 12, 22, 11, 90]
    print("Heap Sort Example:")
    print(f"Original: {arr1}")
    heap_sort(arr1)
    print(f"Sorted: {arr1}")
    
    # Test case 2 with visualization
    print("\n" + "="*50)
    print("Heap Sort with Steps:")
    arr2 = [4, 10, 3, 5, 1]
    heap_sort_with_steps(arr2)
    print(f"Final result: {arr2}")
    
    # Test case 3 - already sorted
    arr3 = [1, 2, 3, 4, 5]
    print(f"\nAlready sorted array: {arr3}")
    heap_sort(arr3)
    print(f"After heap sort: {arr3}")
    
    # Test case 4 - reverse sorted
    arr4 = [5, 4, 3, 2, 1]
    print(f"\nReverse sorted array: {arr4}")
    heap_sort(arr4)
    print(f"After heap sort: {arr4}")
