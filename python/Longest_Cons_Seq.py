#Given an unsorted array of integers nums,
#return the length of the longest consecutive elements sequence.
from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Remove duplicates and sort the numbers
        numbers = list(set(nums))
        numbers.sort()
        
        # Initialize previous number to negative infinity
        prevN = float("-inf")
        # Initialize counters for the longest streak and current streak
        longest = curr = 0
        
        # Iterate through each number in the sorted list
        for n in numbers:
            # If current number is consecutive to previous number
            if n == prevN + 1:
                curr += 1  # Increase current streak
                prevN = n  # Update previous number
            else:
                # If current streak is longer than longest, update longest
                if curr > longest:
                    longest = curr
                # Reset current streak to 1 for new sequence
                curr = 1
                prevN = n  # Update previous number
        
        # Return the maximum of longest streak and current streak
        return longest if longest > curr else curr
