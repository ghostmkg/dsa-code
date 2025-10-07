//https://leetcode.com/problems/move-zeroes/

class Solution {
    public void moveZeroes(int[] nums) {
        int cnt = 0; 
        int index = 0;
        for(int i=0 ; i < nums.length ; i++){
            if(nums[i] == 0) cnt++;
            else{
                nums[index] = nums[i];
                index++;
            }
            
        }
        
        for(int i=nums.length-1 ; i>=nums.length - cnt ; i--){
            nums[i] = 0;
        }
        
        for(int i=0 ; i < nums.length ; i++) System.out.print(nums[i]+" ");
    }
}
