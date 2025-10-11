class MoveZeroes {
    public void moveZeroes(int[] nums) {
        int index = 0; // Tracks where to place the next non-zero element

        // First, move all non-zero elements to the front
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }

        // Fill the rest of the array with zeroes
        while (index < nums.length) {
            nums[index++] = 0;
        }
    }
}
