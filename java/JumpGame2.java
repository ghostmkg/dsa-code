class Solution {
    public int jump(int[] nums) {
        if(nums.length == 1)return 0;

        int range = 0, count = 0, maxInd = 0;

        for(int i=0; i<nums.length; i++){

            range = Math.max(range, i + nums[i]);

            if(i == maxInd){
                maxInd = range;
                count ++;

                if(range >= nums.length-1){
                    return count;
                    }
            }
        }
        return count;
    }
}