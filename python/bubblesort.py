def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # After each pass, the largest element moves to the end
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if elements are in wrong order
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Example usage
numbers = [64, 34, 25, 12, 22, 11, 90]
print("Before sorting:", numbers)

bubble_sort(numbers)

print("After sorting:", numbers)
