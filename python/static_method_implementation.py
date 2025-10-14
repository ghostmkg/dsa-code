# static method is used when a particular method is not object specific
# it can be called using class name
# it does not take self or cls as first argument
# no need to create object of class to call static method

class MaxSubArray:
    """A collection of methods for manipulating array."""

    @staticmethod
    def max_sub_array(nums):
        """Finds the contiguous subarray with the maximum sum value.

        This method calculates the maximum sum of a contiguous
        subarray.

        Args:
            nums : A list of integers.

        Returns:
            The sum of the contiguous subarray with the largest sum.

        Raises:
            ValueError: If the input list `nums` is empty, it raises an value error

        Example:
            >>> MaxSubArray.max_sub_array([-2, 1, -3, 4, -1, 2, 1, -5, 4])
            it will return max valus in a contigous sub array is 6
            # The subarray [4, -1, 2, 1] has the largest sum of 6.
        """
        # Handles the scenario when nums array is empty.
        if not nums:
            raise ValueError("Input array nums can not be empty.")

        max_sum = curr_sum = nums[0]
        for num in nums[1:]:
            curr_sum = max(num, curr_sum + num)
            # Update the overall maximum sum found so far
            max_sum = max(max_sum, curr_sum)

        return max_sum

# --- examples---
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
try:
    max_sum = MaxSubArray.max_sub_array(nums)
    print(f"The maximum sum of a subarray is: {max_sum}")  # Output: 6
except ValueError as e:
    print(f"Error: {e}")