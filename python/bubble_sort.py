"""
Bubble Sort Algorithm Implementation
===================================

Problem: Sort an array of integers in ascending order using bubble sort.

Time Complexity: O(n²) in worst and average case, O(n) in best case
Space Complexity: O(1)

Author: Contributor
Date: October 2025
"""

def bubble_sort(arr):
    """
    Sorts an array using bubble sort algorithm.
    
    Args:
        arr (list): List of integers to be sorted
    
    Returns:
        list: Sorted array in ascending order
    """
    n = len(arr)
    
    # Create a copy to avoid modifying original array
    sorted_arr = arr.copy()
    
    # Traverse through all array elements
    for i in range(n):
        # Flag to optimize - if no swapping occurs, array is sorted
        swapped = False
        
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if sorted_arr[j] > sorted_arr[j + 1]:
                sorted_arr[j], sorted_arr[j + 1] = sorted_arr[j + 1], sorted_arr[j]
                swapped = True
        
        # If no two elements were swapped, array is sorted
        if not swapped:
            break
    
    return sorted_arr


def bubble_sort_inplace(arr):
    """
    Sorts an array in-place using bubble sort algorithm.
    
    Args:
        arr (list): List of integers to be sorted (modified in-place)
    """
    n = len(arr)
    
    for i in range(n):
        swapped = False
        
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        
        if not swapped:
            break


def bubble_sort_with_steps(arr):
    """
    Bubble sort with step-by-step visualization.
    
    Args:
        arr (list): List of integers to be sorted
    
    Returns:
        list: Sorted array
    """
    n = len(arr)
    sorted_arr = arr.copy()
    
    print(f"Initial array: {sorted_arr}")
    print()
    
    for i in range(n):
        swapped = False
        print(f"Pass {i + 1}:")
        
        for j in range(0, n - i - 1):
            if sorted_arr[j] > sorted_arr[j + 1]:
                print(f"  Swapping {sorted_arr[j]} and {sorted_arr[j + 1]}")
                sorted_arr[j], sorted_arr[j + 1] = sorted_arr[j + 1], sorted_arr[j]
                swapped = True
        
        print(f"  After pass {i + 1}: {sorted_arr}")
        print()
        
        if not swapped:
            print("  No swaps needed. Array is sorted!")
            break
    
    return sorted_arr


# Test cases and examples
if __name__ == "__main__":
    print("Bubble Sort Algorithm Demo")
    print("=" * 30)
    
    # Test case 1: Random array
    test_array1 = [64, 34, 25, 12, 22, 11, 90]
    print(f"Original array: {test_array1}")
    sorted_array1 = bubble_sort(test_array1)
    print(f"Sorted array: {sorted_array1}")
    print()
    
    # Test case 2: Already sorted array
    test_array2 = [1, 2, 3, 4, 5]
    print(f"Already sorted array: {test_array2}")
    sorted_array2 = bubble_sort(test_array2)
    print(f"After bubble sort: {sorted_array2}")
    print()
    
    # Test case 3: Reverse sorted array
    test_array3 = [5, 4, 3, 2, 1]
    print(f"Reverse sorted array: {test_array3}")
    sorted_array3 = bubble_sort(test_array3)
    print(f"After bubble sort: {sorted_array3}")
    print()
    
    # Test case 4: Single element
    test_array4 = [42]
    print(f"Single element array: {test_array4}")
    sorted_array4 = bubble_sort(test_array4)
    print(f"After bubble sort: {sorted_array4}")
    print()
    
    # Test case 5: Empty array
    test_array5 = []
    print(f"Empty array: {test_array5}")
    sorted_array5 = bubble_sort(test_array5)
    print(f"After bubble sort: {sorted_array5}")
    print()
    
    # Demonstration with steps
    print("Step-by-step demonstration:")
    print("-" * 30)
    demo_array = [5, 2, 8, 1, 9]
    bubble_sort_with_steps(demo_array)