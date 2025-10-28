# sliding_window_maximum.py
# Find the maximum in each sliding window of size k in an array
from collections import deque
from typing import List

def sliding_window_maximum(nums: List[int], k: int) -> List[int]:
    if not nums or k == 0:
        return []
    dq = deque()
    result = []
    for i, num in enumerate(nums):
        while dq and dq[0] <= i - k:
            dq.popleft()
        while dq and nums[dq[-1]] < num:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            result.append(nums[dq[0]])
    return result

if __name__ == "__main__":
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    print("Sliding window maximums:", sliding_window_maximum(nums, k))
