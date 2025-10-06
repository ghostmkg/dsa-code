import java.util.*;

class Solution {
    public long countSubarrays(int[] nums, int k) {
        long maxNum = Long.MIN_VALUE, count = 0;
        long left = 0, right = 0, ans = 0;
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
        }
        while (right < nums.length || left > right) {
            if (nums[(int)right] == maxNum) {
                count++;
            }
            while (count >= k) {
                if (nums[(int)left] == maxNum) {
                    count--;
                }
                left++;
                ans += nums.length - right;
            }
            right++;
        }
        return ans;
    }
    public static void main(String args[]) {
        Solution find = new Solution();
        Scanner sc = new Scanner(System.in);

        //enter array length
        int n = sc.nextInt();

        //array created
        int nums[] = new int[n];

        //taking inputs
        for(int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        //taking k elemnt(k times condition)
        int k = sc.nextInt();

        //output on screen
        System.out.println(find.countSubarrays(nums, k));
    }
}