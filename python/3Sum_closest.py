class Solution:
    def threeSumClosest(self, nums, target):
        """
        Finds the sum of three integers in nums such that the sum is closest to the target.

        :param nums: List[int] - input list of integers
        :param target: int - the target sum
        :return: int - the closest sum of three elements to the target
        """
        nums.sort()
        n = len(nums)
        closest_sum = float('inf')

        for i in range(n - 2):
            # Skip duplicates for the first number
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, n - 1

            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]

                # Update closest sum if needed
                if abs(target - current_sum) < abs(target - closest_sum):
                    closest_sum = current_sum

                # Move pointers according to comparison
                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else:
                    # Exact match found
                    return current_sum

        return closest_sum
