class Solution:
    def rob(self, nums):
        rob1, rob2 = 0, 0
        max_val = 0

        for n in nums:
            max_val = max(n + rob1, rob2)
            rob1 = rob2
            rob2 = max_val

        return max_val


# Main function to run the code
if __name__ == "__main__":
    # Example input
    nums = [2, 7, 9, 3, 1]   # You can change this test case
    solution = Solution()
    result = solution.rob(nums)
    print("Maximum amount that can be robbed:", result)
