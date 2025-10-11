import java.util.HashMap;

class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>(); // Stores number → index

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i]; // The number needed to reach target

            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i}; // Found the pair
            }

            map.put(nums[i], i); // Store current number and its index
        }

        return new int[]{}; // If no pair found
    }
}

