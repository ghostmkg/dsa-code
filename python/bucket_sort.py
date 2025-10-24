# Bucket Sort Algorithm
# Time Complexity: O(n + k) average case, O(n^2) worst case
# Space Complexity: O(n + k)
# Stable sorting algorithm (when using stable sorting for individual buckets)

def bucket_sort(arr):
    """
    Bucket sort implementation for floating point numbers in range [0, 1).
    """
    if not arr:
        return arr
    
    n = len(arr)
    
    # Create n empty buckets
    buckets = [[] for _ in range(n)]
    
    # Put array elements in different buckets
    for i in range(n):
        bucket_index = int(n * arr[i])
        buckets[bucket_index].append(arr[i])
    
    # Sort individual buckets using insertion sort
    for i in range(n):
        insertion_sort(buckets[i])
    
    # Concatenate all buckets into arr[]
    index = 0
    for i in range(n):
        for j in range(len(buckets[i])):
            arr[index] = buckets[i][j]
            index += 1

def insertion_sort(bucket):
    """
    Insertion sort for individual buckets.
    """
    for i in range(1, len(bucket)):
        key = bucket[i]
        j = i - 1
        while j >= 0 and bucket[j] > key:
            bucket[j + 1] = bucket[j]
            j -= 1
        bucket[j + 1] = key

def bucket_sort_integers(arr, bucket_size=10):
    """
    Bucket sort for integers with custom bucket size.
    """
    if not arr:
        return arr
    
    # Find min and max values
    min_val = min(arr)
    max_val = max(arr)
    
    # Calculate number of buckets needed
    num_buckets = (max_val - min_val) // bucket_size + 1
    buckets = [[] for _ in range(num_buckets)]
    
    # Distribute elements into buckets
    for num in arr:
        bucket_index = (num - min_val) // bucket_size
        buckets[bucket_index].append(num)
    
    # Sort each bucket and concatenate
    result = []
    for bucket in buckets:
        insertion_sort(bucket)
        result.extend(bucket)
    
    return result

def bucket_sort_with_steps(arr):
    """
    Bucket sort with step-by-step visualization.
    """
    print(f"Original array: {arr}")
    n = len(arr)
    
    # Create buckets
    buckets = [[] for _ in range(n)]
    print(f"Created {n} empty buckets")
    
    # Distribute elements
    print("\nDistributing elements into buckets:")
    for i in range(n):
        bucket_index = int(n * arr[i])
        buckets[bucket_index].append(arr[i])
        print(f"Element {arr[i]} goes to bucket {bucket_index}")
    
    print(f"\nBuckets after distribution: {buckets}")
    
    # Sort individual buckets
    print("\nSorting individual buckets:")
    for i in range(n):
        if buckets[i]:
            print(f"Sorting bucket {i}: {buckets[i]}")
            insertion_sort(buckets[i])
            print(f"After sorting: {buckets[i]}")
    
    # Concatenate
    print("\nConcatenating sorted buckets:")
    result = []
    for i in range(n):
        if buckets[i]:
            result.extend(buckets[i])
            print(f"After adding bucket {i}: {result}")
    
    return result

def bucket_sort_strings(arr):
    """
    Bucket sort for strings based on first character.
    """
    if not arr:
        return arr
    
    # Create buckets for each letter
    buckets = [[] for _ in range(26)]
    
    # Distribute strings into buckets
    for s in arr:
        if s:  # Check if string is not empty
            bucket_index = ord(s[0].lower()) - ord('a')
            buckets[bucket_index].append(s)
    
    # Sort each bucket and concatenate
    result = []
    for bucket in buckets:
        if bucket:
            insertion_sort(bucket)
            result.extend(bucket)
    
    return result

# Example usage
if __name__ == "__main__":
    # Test case 1 - floating point numbers
    print("Bucket Sort for Floating Point Numbers [0, 1):")
    arr1 = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
    print(f"Original: {arr1}")
    bucket_sort(arr1)
    print(f"Sorted: {arr1}")
    
    # Test case 2 with steps
    print("\n" + "="*60)
    print("Bucket Sort with Steps:")
    arr2 = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
    result = bucket_sort_with_steps(arr2)
    print(f"Final result: {result}")
    
    # Test case 3 - integers
    print("\n" + "="*60)
    print("Bucket Sort for Integers:")
    arr3 = [64, 34, 25, 12, 22, 11, 90, 5]
    print(f"Original: {arr3}")
    sorted_arr3 = bucket_sort_integers(arr3)
    print(f"Sorted: {sorted_arr3}")
    
    # Test case 4 - strings
    print("\n" + "="*60)
    print("Bucket Sort for Strings:")
    words = ["apple", "banana", "cherry", "date", "elderberry", "fig"]
    print(f"Original: {words}")
    sorted_words = bucket_sort_strings(words)
    print(f"Sorted: {sorted_words}")
    
    # Test case 5 - edge cases
    print("\n" + "="*60)
    print("Edge Cases:")
    print("Empty array:", bucket_sort([]))
    print("Single element:", bucket_sort([0.5]))
    print("All same elements:", bucket_sort([0.3, 0.3, 0.3, 0.3]))
