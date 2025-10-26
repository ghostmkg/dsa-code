class Solution(object):
    def firstMissingPositive(self,nums):
        nums = [n for n in nums if n>0]
        nums.sort()

        target_num= 1
        for n in nums:
            if n == target_num:
                target_num += 1
            elif n>target_num:
                return target_num   

        return target_num         