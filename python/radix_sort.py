# Radix Sort Algorithm
# Time Complexity: O(d * (n + k)) where d is number of digits, k is range of digits
# Space Complexity: O(n + k)
# Stable sorting algorithm

def counting_sort_by_digit(arr, exp):
    """
    A function to do counting sort of arr[] according to the digit represented by exp.
    """
    n = len(arr)
    output = [0] * n  # output array
    count = [0] * 10  # count array for digits 0-9
    
    # Store count of occurrences in count[]
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    
    # Change count[i] so that count[i] now contains actual position of this digit in output[]
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    # Build the output array
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1
    
    # Copy the output array to arr[], so that arr[] now contains sorted numbers
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    """
    Main function to implement radix sort.
    """
    # Find the maximum number to know number of digits
    max_num = max(arr)
    
    # Do counting sort for every digit
    exp = 1
    while max_num // exp > 0:
        counting_sort_by_digit(arr, exp)
        exp *= 10

def radix_sort_with_steps(arr):
    """
    Radix sort with step-by-step visualization.
    """
    print(f"Original array: {arr}")
    max_num = max(arr)
    print(f"Maximum number: {max_num}")
    
    exp = 1
    step = 1
    while max_num // exp > 0:
        print(f"\nStep {step}: Sorting by digit at position {exp}")
        print(f"Before sorting by digit: {arr}")
        counting_sort_by_digit(arr, exp)
        print(f"After sorting by digit: {arr}")
        exp *= 10
        step += 1
    
    return arr

def radix_sort_strings(arr):
    """
    Radix sort for strings (lexicographic order).
    """
    if not arr:
        return arr
    
    # Find the maximum length
    max_len = max(len(s) for s in arr)
    
    # Pad strings with spaces to make them same length
    padded_arr = [s.ljust(max_len) for s in arr]
    
    # Sort by each character position from right to left
    for pos in range(max_len - 1, -1, -1):
        # Use counting sort for this position
        count = [0] * 256  # ASCII range
        output = [''] * len(padded_arr)
        
        # Count occurrences
        for s in padded_arr:
            count[ord(s[pos])] += 1
        
        # Calculate positions
        for i in range(1, 256):
            count[i] += count[i - 1]
        
        # Build output array
        for i in range(len(padded_arr) - 1, -1, -1):
            output[count[ord(padded_arr[i][pos])] - 1] = padded_arr[i]
            count[ord(padded_arr[i][pos])] -= 1
        
        padded_arr = output
    
    # Remove padding and return
    return [s.rstrip() for s in padded_arr]

# Example usage
if __name__ == "__main__":
    # Test case 1 - integers
    print("Radix Sort for Integers:")
    arr1 = [170, 45, 75, 90, 2, 802, 24, 66]
    print(f"Original: {arr1}")
    radix_sort(arr1)
    print(f"Sorted: {arr1}")
    
    # Test case 2 with steps
    print("\n" + "="*50)
    print("Radix Sort with Steps:")
    arr2 = [329, 457, 657, 839, 436, 720, 355]
    radix_sort_with_steps(arr2)
    print(f"Final result: {arr2}")
    
    # Test case 3 - strings
    print("\n" + "="*50)
    print("Radix Sort for Strings:")
    words = ["word", "category", "apple", "banana", "cat", "dog"]
    print(f"Original: {words}")
    sorted_words = radix_sort_strings(words)
    print(f"Sorted: {sorted_words}")
    
    # Test case 4 - negative numbers (requires modification)
    print("\n" + "="*50)
    print("Note: This implementation doesn't handle negative numbers.")
    print("For negative numbers, you would need to separate positive and negative arrays.")
