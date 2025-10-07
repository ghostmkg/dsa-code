//LeetCode 1. Two Sum
//Question Link - https://leetcode.com/problems/two-sum/

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int result[] = new int[2];
        
        //to store the numbers which have already been encountered
        //key = number in array, value = index of the number
        Map<Integer, Integer> seen = new HashMap<>();
        
        for(int i = 0 ; i < nums.length ; i++){
            //the number nums[i] is alreday in the array
            //check if (target - nums[i]) is also in the array or not 
            int complement = target - nums[i];
            
            //we check if we have already encountered complement or not.
            if(seen.containsKey(complement)){
                return new int[]{seen.get(complement), i};
            }
            
            //if complement does not exsist, we must store the current number in seen
            //The current number could be the complement of some number to be visited further in the array
            seen.put(nums[i], i);
        }
        
        return result;
    }
}
