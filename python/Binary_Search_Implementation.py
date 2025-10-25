# File name: Binary_Search_Implementation.py

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

# Example usage:
if __name__ == "__main__":
    array = [1, 3, 5, 7, 9, 11, 13]
    target = 7
    result = binary_search(array, target)
    if result != -1:
        print(f"Element {target} found at index {result}")
    else:
        print(f"Element {target} not found in array")
