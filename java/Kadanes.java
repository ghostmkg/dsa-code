import java.util.*;

//kadane's Algorithm is the most optimized
//solution for finding maximum subarray sum and it is also most important algorithm for placements

public class Kadanes{
    public static int maxSub(int[] nums){
        int maxi = nums[0];
        int curr = nums[0];

        for(int i = 1; i<nums.length; i++){
            curr = Math.max(nums[i], curr + nums[i]);
            maxi = Math.max(max, curr);

        }
        return maxi;
    }
     public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Maximum Subarray Sum = " + maxSubArray(nums));
    }
}
