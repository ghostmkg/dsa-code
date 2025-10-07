class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []

        def backtrack(l, r):
            res.append(r[:]) 
            for i in range(l, len(nums)):
                r.append(nums[i])
                backtrack(i + 1, r)
                r.pop()

        backtrack(0, [])
        return res