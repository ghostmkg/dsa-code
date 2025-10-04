public class KadanesAlgorithm {
    public static int maxSubArraySum(int[] nums) {
        int maxSoFar = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            // Either take current element or add it to current sum
            currentSum = Math.max(nums[i], currentSum + nums[i]);

            // Update max if needed
            maxSoFar = Math.max(maxSoFar, currentSum);
        }

        return maxSoFar;
    }

    public static void main(String[] args) {
        int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int maxSum = maxSubArraySum(arr);
        System.out.println("Maximum Subarray Sum = " + maxSum);
    }
}
