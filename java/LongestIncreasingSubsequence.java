import java.util.*;

public class LongestIncreasingSubsequence {

    public static int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;

        
        int[] tail = new int[nums.length];
        int size = 0;

        for (int num : nums) {
           
            int i = Arrays.binarySearch(tail, 0, size, num);

            
            if (i < 0) i = -(i + 1);

            tail[i] = num;

         
            if (i == size) size++;
        }

        return size;
    }

   
    public static void main(String[] args) {
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println("Length of Longest Increasing Subsequence: " + lengthOfLIS(nums));
    }
}
