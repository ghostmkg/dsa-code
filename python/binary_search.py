"""
Binary Search Algorithm Implementation
=====================================

Problem: Given a sorted array and a target value, find the index of the target value.
If not found, return -1.

Time Complexity: O(log n)
Space Complexity: O(1)

Author: Contributor
Date: October 2025
"""

def binary_search(arr, target):
    """
    Performs binary search on a sorted array.
    
    Args:
        arr (list): Sorted array of integers
        target (int): Target value to search for
    
    Returns:
        int: Index of target if found, -1 otherwise
    """
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        # Calculate middle index to avoid overflow
        mid = left + (right - left) // 2
        
        # If target found at mid
        if arr[mid] == target:
            return mid
        
        # If target is smaller, search left half
        elif arr[mid] > target:
            right = mid - 1
        
        # If target is larger, search right half
        else:
            left = mid + 1
    
    # Target not found
    return -1


def binary_search_recursive(arr, target, left=0, right=None):
    """
    Recursive implementation of binary search.
    
    Args:
        arr (list): Sorted array of integers
        target (int): Target value to search for
        left (int): Left boundary index
        right (int): Right boundary index
    
    Returns:
        int: Index of target if found, -1 otherwise
    """
    if right is None:
        right = len(arr) - 1
    
    # Base case: element not found
    if left > right:
        return -1
    
    # Calculate middle index
    mid = left + (right - left) // 2
    
    # If target found at mid
    if arr[mid] == target:
        return mid
    
    # If target is smaller, search left half
    elif arr[mid] > target:
        return binary_search_recursive(arr, target, left, mid - 1)
    
    # If target is larger, search right half
    else:
        return binary_search_recursive(arr, target, mid + 1, right)


# Test cases and examples
if __name__ == "__main__":
    # Test array (must be sorted for binary search)
    test_array = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    
    print("Binary Search Algorithm Demo")
    print("=" * 30)
    print(f"Array: {test_array}")
    print()
    
    # Test cases
    test_cases = [7, 1, 19, 10, 20, -1]
    
    for target in test_cases:
        # Iterative approach
        result_iter = binary_search(test_array, target)
        
        # Recursive approach
        result_rec = binary_search_recursive(test_array, target)
        
        print(f"Searching for {target}:")
        print(f"  Iterative result: {result_iter}")
        print(f"  Recursive result: {result_rec}")
        
        if result_iter != -1:
            print(f"  Found at index {result_iter}, value: {test_array[result_iter]}")
        else:
            print(f"  {target} not found in array")
        print()