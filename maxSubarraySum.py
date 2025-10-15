class Solution:
    def maxSubarraySum(self, arr):
        # initailize the length of the array as n 
        n = len(arr)
        # initialize the the result as the array[0] 
        res = arr[0]
        # initialize the maximum sum of the array as arr[0]
        maxEnding = arr[0]
        # iterate the loop from index 1 to the lenght of the array
        for i in range (1, n):
            # max sum of the sub array is the maximum of the current maxending or arr[i]
            maxEnding = max(maxEnding + arr[i], arr[i])
            # result will be the maximum of the result or maxEnding
            res = max(maxEnding , res)
            
        return res
        
if __name__== "__main__":
    arr =  [1,2,3,4,-3,-6]
    obj = Solution()
    obj.maxSubarraySum(arr)
        
