def search_in_rotated_array(nums, target):
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        # Found target
        if nums[mid] == target:
            return mid

        # Check if left half is sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        # Right half is sorted
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1

    # Target not found
    return -1


# Example usage:
nums = [4, 5, 6, 7, 0, 1, 2]
target = 0
result = search_in_rotated_array(nums, target)
print("Index of target:", result)
