class longestSubsequencewithXOR {
public int longestSubsequence(int[] nums) {
        int xor = 0;  // Variable to store cumulative XOR of all elements

        // Compute XOR of all numbers in the array
        for (int num : nums) {
            xor = xor ^ num;
        }

        // If the total XOR is non-zero, the entire array itself is a valid subsequence
        if (xor != 0) {
            return nums.length;
        }

        // If total XOR is zero, check if there's at least one non-zero element
        // Removing any one non-zero element will make the XOR non-zero
        for (int num : nums) {
            if (num != 0) {
                return nums.length - 1;
            }
        }

        // If all elements are zero, no non-zero XOR subsequence exists
        return 0;
    }
}