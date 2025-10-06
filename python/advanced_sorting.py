def counting_sort(arr, exp=1):
    """
    Counting sort for a specific digit position
    Used as a subroutine in radix sort
    """
    n = len(arr)
    output = [0] * n
    count = [0] * 10  # For digits 0-9
    
    # Count occurrences of each digit
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    
    # Change count[i] to actual position
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    # Build output array
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1
    
    # Copy output array to arr
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    """
    Radix sort algorithm implementation
    Time Complexity: O(d * (n + k)) where d is digits, k is range
    Space Complexity: O(n + k)
    """
    if not arr:
        return arr
    
    # Find maximum number to know number of digits
    max_num = max(arr)
    
    # Do counting sort for every digit
    exp = 1
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10
    
    return arr

def bucket_sort(arr, num_buckets=10):
    """
    Bucket sort algorithm implementation
    Time Complexity: O(n + k) average case, O(n²) worst case
    Space Complexity: O(n + k)
    """
    if len(arr) <= 1:
        return arr
    
    # Find minimum and maximum values
    min_val = min(arr)
    max_val = max(arr)
    
    # Calculate bucket range
    bucket_range = (max_val - min_val) / num_buckets
    
    # Create empty buckets
    buckets = [[] for _ in range(num_buckets)]
    
    # Put array elements into buckets
    for num in arr:
        if num == max_val:
            bucket_index = num_buckets - 1
        else:
            bucket_index = int((num - min_val) / bucket_range)
        buckets[bucket_index].append(num)
    
    # Sort individual buckets and concatenate
    sorted_arr = []
    for bucket in buckets:
        if bucket:
            bucket.sort()  # Using built-in sort for individual buckets
            sorted_arr.extend(bucket)
    
    return sorted_arr

def shell_sort(arr):
    """
    Shell sort algorithm implementation
    Time Complexity: O(n log n) to O(n²) depending on gap sequence
    Space Complexity: O(1)
    """
    n = len(arr)
    gap = n // 2
    
    while gap > 0:
        # Perform insertion sort with gap
        for i in range(gap, n):
            temp = arr[i]
            j = i
            
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            
            arr[j] = temp
        
        gap //= 2
    
    return arr

def cocktail_sort(arr):
    """
    Cocktail sort (bidirectional bubble sort) implementation
    Time Complexity: O(n²)
    Space Complexity: O(1)
    """
    n = len(arr)
    start = 0
    end = n - 1
    swapped = True
    
    while swapped:
        swapped = False
        
        # Forward pass
        for i in range(start, end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
        
        if not swapped:
            break
        
        end -= 1
        swapped = False
        
        # Backward pass
        for i in range(end - 1, start - 1, -1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
        
        start += 1
    
    return arr

def gnome_sort(arr):
    """
    Gnome sort algorithm implementation
    Time Complexity: O(n²)
    Space Complexity: O(1)
    """
    index = 0
    n = len(arr)
    
    while index < n:
        if index == 0:
            index += 1
        elif arr[index] >= arr[index - 1]:
            index += 1
        else:
            arr[index], arr[index - 1] = arr[index - 1], arr[index]
            index -= 1
    
    return arr

def comb_sort(arr):
    """
    Comb sort algorithm implementation
    Time Complexity: O(n²) worst case, O(n log n) average
    Space Complexity: O(1)
    """
    n = len(arr)
    gap = n
    shrink = 1.3
    swapped = True
    
    while gap > 1 or swapped:
        # Update gap
        gap = int(gap / shrink)
        if gap < 1:
            gap = 1
        
        swapped = False
        
        # Compare elements with gap
        for i in range(n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True
    
    return arr

def pancake_sort(arr):
    """
    Pancake sort algorithm implementation
    Time Complexity: O(n²)
    Space Complexity: O(1)
    """
    def flip(arr, k):
        """Flip elements from 0 to k"""
        left = 0
        while left < k:
            arr[left], arr[k] = arr[k], arr[left]
            left += 1
            k -= 1
    
    def find_max_index(arr, n):
        """Find index of maximum element in arr[0..n-1]"""
        max_idx = 0
        for i in range(1, n):
            if arr[i] > arr[max_idx]:
                max_idx = i
        return max_idx
    
    n = len(arr)
    
    for curr_size in range(n, 1, -1):
        # Find index of maximum element in arr[0..curr_size-1]
        max_idx = find_max_index(arr, curr_size)
        
        # If maximum is not at the end, move it to the end
        if max_idx != curr_size - 1:
            # Move maximum to beginning if it's not already there
            if max_idx != 0:
                flip(arr, max_idx)
            
            # Move maximum to the end
            flip(arr, curr_size - 1)
    
    return arr

def compare_sorting_algorithms():
    """
    Compare different sorting algorithms with sample data
    """
    import time
    import random
    
    # Generate test data
    test_data = [random.randint(1, 1000) for _ in range(100)]
    
    algorithms = [
        ("Radix Sort", radix_sort),
        ("Bucket Sort", bucket_sort),
        ("Shell Sort", shell_sort),
        ("Cocktail Sort", cocktail_sort),
        ("Gnome Sort", gnome_sort),
        ("Comb Sort", comb_sort),
        ("Pancake Sort", pancake_sort)
    ]
    
    print("Comparing sorting algorithms with 100 random integers:")
    print("=" * 60)
    
    for name, algorithm in algorithms:
        data_copy = test_data.copy()
        
        start_time = time.time()
        sorted_data = algorithm(data_copy)
        end_time = time.time()
        
        execution_time = (end_time - start_time) * 1000  # Convert to milliseconds
        is_sorted = sorted_data == sorted(test_data)
        
        print(f"{name:15} | Time: {execution_time:8.4f}ms | Correct: {is_sorted}")

# Test the advanced sorting algorithms
if __name__ == "__main__":
    # Test each algorithm individually
    test_array = [170, 45, 75, 90, 2, 802, 24, 66]
    print(f"Original array: {test_array}")
    print("=" * 50)
    
    # Test Radix Sort
    radix_result = radix_sort(test_array.copy())
    print(f"Radix Sort:    {radix_result}")
    
    # Test Bucket Sort
    bucket_result = bucket_sort(test_array.copy())
    print(f"Bucket Sort:   {bucket_result}")
    
    # Test Shell Sort
    shell_result = shell_sort(test_array.copy())
    print(f"Shell Sort:    {shell_result}")
    
    # Test Cocktail Sort
    cocktail_result = cocktail_sort(test_array.copy())
    print(f"Cocktail Sort: {cocktail_result}")
    
    # Test Gnome Sort
    gnome_result = gnome_sort(test_array.copy())
    print(f"Gnome Sort:    {gnome_result}")
    
    # Test Comb Sort
    comb_result = comb_sort(test_array.copy())
    print(f"Comb Sort:     {comb_result}")
    
    # Test Pancake Sort
    pancake_result = pancake_sort(test_array.copy())
    print(f"Pancake Sort:  {pancake_result}")
    
    print("\n" + "=" * 50)
    # Compare performance
    compare_sorting_algorithms()