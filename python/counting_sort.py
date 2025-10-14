"""
Counting Sort Algorithm Implementation

Counting Sort is a non-comparison based sorting algorithm that works well
when the range of input data (k) is not significantly larger than the number
of objects to be sorted (n). It has a time complexity of O(n+k).

Time Complexity: O(n + k) where n is the number of elements and k is the range
Space Complexity: O(k) for the count array

Advantages:
- Stable sorting algorithm
- Linear time complexity when k = O(n)
- Doesn't use comparisons

Disadvantages:
- Not suitable for large ranges of input data
- Only works with non-negative integers (or can be modified for other types)
"""

def counting_sort(arr):
    """
    Sorts an array using the counting sort algorithm.
    
    Args:
        arr (list): List of non-negative integers to be sorted
        
    Returns:
        list: Sorted array in ascending order
        
    Example:
        >>> counting_sort([4, 2, 2, 8, 3, 3, 1])
        [1, 2, 2, 3, 3, 4, 8]
    """
    if not arr:
        return arr
    
    # Find the maximum element to determine the range
    max_val = max(arr)
    min_val = min(arr)
    
    # Handle negative numbers by shifting the range
    range_size = max_val - min_val + 1
    
    # Create count array to store count of each element
    count = [0] * range_size
    
    # Store count of each element
    for num in arr:
        count[num - min_val] += 1
    
    # Modify count array to store actual positions
    for i in range(1, range_size):
        count[i] += count[i - 1]
    
    # Build the result array
    result = [0] * len(arr)
    
    # Build result array from right to left to maintain stability
    for i in range(len(arr) - 1, -1, -1):
        result[count[arr[i] - min_val] - 1] = arr[i]
        count[arr[i] - min_val] -= 1
    
    return result

def counting_sort_simple(arr):
    """
    Simple version of counting sort for educational purposes.
    Works only with non-negative integers starting from 0.
    
    Args:
        arr (list): List of non-negative integers to be sorted
        
    Returns:
        list: Sorted array in ascending order
    """
    if not arr:
        return arr
    
    max_val = max(arr)
    count = [0] * (max_val + 1)
    
    # Count occurrences of each element
    for num in arr:
        count[num] += 1
    
    # Reconstruct the sorted array
    result = []
    for i in range(len(count)):
        result.extend([i] * count[i])
    
    return result

def demonstrate_counting_sort():
    """
    Demonstrates the counting sort algorithm with various test cases.
    """
    print("=== Counting Sort Demonstration ===\n")
    
    test_cases = [
        [4, 2, 2, 8, 3, 3, 1],
        [1, 4, 1, 2, 7, 5, 2],
        [1, 1, 1, 1],
        [5, 4, 3, 2, 1],
        [1, 2, 3, 4, 5],
        [],
        [42],
        [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    ]
    
    for i, test_case in enumerate(test_cases, 1):
        print(f"Test Case {i}:")
        print(f"Original: {test_case}")
        sorted_arr = counting_sort(test_case.copy())
        print(f"Sorted:   {sorted_arr}")
        print(f"Verification: {sorted_arr == sorted(test_case)}")
        print("-" * 40)

def counting_sort_with_objects(arr, key_func):
    """
    Counting sort implementation that works with objects.
    
    Args:
        arr (list): List of objects to be sorted
        key_func (function): Function to extract the sorting key from objects
        
    Returns:
        list: Sorted array based on the key function
    """
    if not arr:
        return arr
    
    # Extract keys and find range
    keys = [key_func(obj) for obj in arr]
    max_key = max(keys)
    min_key = min(keys)
    range_size = max_key - min_key + 1
    
    # Create buckets for each possible key value
    buckets = [[] for _ in range(range_size)]
    
    # Place objects in appropriate buckets
    for obj in arr:
        key = key_func(obj)
        buckets[key - min_key].append(obj)
    
    # Concatenate all buckets to get sorted result
    result = []
    for bucket in buckets:
        result.extend(bucket)
    
    return result

# Example usage and testing
if __name__ == "__main__":
    # Run demonstration
    demonstrate_counting_sort()
    
    # Test with objects
    print("\n=== Counting Sort with Objects ===")
    
    class Student:
        def __init__(self, name, grade):
            self.name = name
            self.grade = grade
        
        def __repr__(self):
            return f"Student({self.name}, {self.grade})"
    
    students = [
        Student("Alice", 85),
        Student("Bob", 90),
        Student("Charlie", 85),
        Student("David", 95),
        Student("Eve", 80)
    ]
    
    print("Original students:")
    for student in students:
        print(f"  {student}")
    
    sorted_students = counting_sort_with_objects(students, lambda s: s.grade)
    
    print("\nSorted by grade:")
    for student in sorted_students:
        print(f"  {student}")
    
    # Performance comparison
    print("\n=== Performance Test ===")
    import time
    import random
    
    # Generate random data
    large_arr = [random.randint(0, 1000) for _ in range(10000)]
    
    # Test counting sort
    start_time = time.time()
    counting_sorted = counting_sort(large_arr.copy())
    counting_time = time.time() - start_time
    
    # Test built-in sort
    start_time = time.time()
    builtin_sorted = sorted(large_arr)
    builtin_time = time.time() - start_time
    
    print(f"Counting Sort time: {counting_time:.4f} seconds")
    print(f"Built-in Sort time: {builtin_time:.4f} seconds")
    print(f"Results match: {counting_sorted == builtin_sorted}")
    
    if counting_time < builtin_time:
        print("Counting Sort is faster!")
    else:
        print("Built-in Sort is faster!")