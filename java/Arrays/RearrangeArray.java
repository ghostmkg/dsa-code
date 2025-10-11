class RearrangeArray {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;                 // Get the total number of elements in the input array
        int ans[] = new int[n];              // Create a new array to store the rearranged elements

        int pos = 0;                         // Pointer for placing positive numbers (even indices)
        int neg = 1;                         // Pointer for placing negative numbers (odd indices)

        // Traverse through each element in the input array
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {               // If the current number is positive
                ans[pos] = nums[i];          // Place it at the current positive index
                pos = pos + 2;               // Move to the next positive position (skip one index)
            } else {                         // Otherwise, it's a negative number
                ans[neg] = nums[i];          // Place it at the current negative index
                neg = neg + 2;               // Move to the next negative position
            }
        }

        return ans;                          // Return the rearranged array
    }
}
