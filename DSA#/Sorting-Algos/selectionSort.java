# Selection Sort in Python

def selection_sort(arr):
    # Loop through all elements in the array
    for i in range(len(arr)):
        # Assume the current index has the smallest element
        min_index = i

        # Find the smallest element in the remaining unsorted part
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j  # Update index of smallest element

        # Swap the found smallest element with the first element of unsorted part
        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr  # Return the sorted array


# Example usage
arr = [64, 25, 12, 22, 11]
print("Original array:", arr)

sorted_arr = selection_sort(arr)
print("Sorted array:", sorted_arr)
