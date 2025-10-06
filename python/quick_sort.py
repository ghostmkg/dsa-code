def quick_sort(arr):
    """
    Quick sort algorithm implementation
    Time Complexity: O(n log n) average, O(n²) worst case
    Space Complexity: O(log n)
    """
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return quick_sort(left) + middle + quick_sort(right)

def quick_sort_inplace(arr, low=0, high=None):
    """
    In-place quick sort implementation
    """
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Partition the array and get pivot index
        pivot_index = partition(arr, low, high)
        
        # Sort elements before and after partition
        quick_sort_inplace(arr, low, pivot_index - 1)
        quick_sort_inplace(arr, pivot_index + 1, high)

def partition(arr, low, high):
    """
    Partition function for quick sort
    Uses last element as pivot
    """
    pivot = arr[high]
    i = low - 1  # Index of smaller element
    
    for j in range(low, high):
        # If current element is smaller than or equal to pivot
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort_random_pivot(arr, low=0, high=None):
    """
    Quick sort with random pivot selection
    Better average case performance
    """
    import random
    
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Choose random pivot and swap with last element
        random_index = random.randint(low, high)
        arr[random_index], arr[high] = arr[high], arr[random_index]
        
        pivot_index = partition(arr, low, high)
        quick_sort_random_pivot(arr, low, pivot_index - 1)
        quick_sort_random_pivot(arr, pivot_index + 1, high)

def quick_select(arr, k):
    """
    Quick select algorithm to find kth smallest element
    Time Complexity: O(n) average case
    """
    if not arr:
        return None
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    if k < len(left):
        return quick_select(left, k)
    elif k < len(left) + len(middle):
        return pivot
    else:
        return quick_select(right, k - len(left) - len(middle))

# Test the functions
if __name__ == "__main__":
    # Test quick sort
    numbers = [64, 34, 25, 12, 22, 11, 90]
    print(f"Original array: {numbers}")
    
    sorted_numbers = quick_sort(numbers.copy())
    print(f"Quick sorted: {sorted_numbers}")
    
    # Test in-place quick sort
    inplace_numbers = numbers.copy()
    quick_sort_inplace(inplace_numbers)
    print(f"In-place quick sorted: {inplace_numbers}")
    
    # Test random pivot quick sort
    random_numbers = numbers.copy()
    quick_sort_random_pivot(random_numbers)
    print(f"Random pivot sorted: {random_numbers}")
    
    # Test quick select
    test_array = [3, 6, 8, 10, 1, 2, 1]
    k = 3
    kth_smallest = quick_select(test_array, k - 1)  # k-1 for 0-based indexing
    print(f"\n{k}rd smallest element in {test_array}: {kth_smallest}")
    
    # Find median using quick select
    sorted_test = sorted(test_array)
    median_index = len(test_array) // 2
    median = quick_select(test_array, median_index)
    print(f"Median of {sorted_test}: {median}")
