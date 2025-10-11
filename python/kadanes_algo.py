
# Program Name:
# Maximum Subarray Sum using Kadane’s Algorithm

# Problem Statement:
# Given an array of integers, find the contiguous subarray (containing at least one number) 
# which has the largest sum and return its sum.

# Example 1:
# Input: arr = [-2,1,-3,4,-1,2,1,-5,4]
# Output: 6
# Explanation: Subarray [4,-1,2,1] has the maximum sum = 6

# Approach:
# Use Kadane’s Algorithm:
# - Initialize max_sum and current_sum with arr[0]
# - Traverse the array:
#     current_sum = max(arr[i], current_sum + arr[i])
#     max_sum = max(max_sum, current_sum)
# - Return max_sum


def kadane(arr):
    max_sum = current_sum = arr[0]
    for num in arr[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    return max_sum

if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    arr = list(map(int, input("Enter the elements: ").split()))
    print("Maximum Subarray Sum:", kadane(arr))
