# File: python/binary_search.py

def binary_search(arr, target):
    """
    Searches for a target value in a sorted array (list) using the Binary Search algorithm.
    
    Args:
        arr (list): A list of sorted numbers (integers or floats).
        target: The value to search for.

    Returns:
        int: The index of the target in the array, or -1 if the target is not found.
    """
    low = 0
    high = len(arr) - 1

    while low <= high:
        # Calculate the middle index
        mid = (low + high) // 2
        
        # Check if the target is present at the middle
        if arr[mid] == target:
            return mid
        
        # If the target is greater than the middle element, ignore the left half
        elif arr[mid] < target:
            low = mid + 1
            
        # If the target is smaller than the middle element, ignore the right half
        else:
            high = mid - 1
            
    # If the target is not found after the loop finishes
    return -1

# --- Example Usage ---
if __name__ == '__main__':
    # 1. Test with a number that is present
    sorted_list = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    target_value = 23
    
    result_index = binary_search(sorted_list, target_value)
    
    if result_index != -1:
        print(f"Target {target_value} found at index: {result_index}") # Output: 5
    else:
        print(f"Target {target_value} not found.")

    # 2. Test with a number that is NOT present
    target_not_present = 42
    result_index_miss = binary_search(sorted_list, target_not_present)
    
    if result_index_miss != -1:
        print(f"Target {target_not_present} found at index: {result_index_miss}")
    else:
        print(f"Target {target_not_present} not found.") # Output: -1