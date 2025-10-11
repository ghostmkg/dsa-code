class MaximumSubarray {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];     // Best sum so far
        int currentSum = nums[0]; // Current subarray sum

        for (int i = 1; i < nums.length; i++) {
            // If currentSum becomes negative, start new subarray
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
}
