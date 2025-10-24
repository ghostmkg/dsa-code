import java.util.*;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        
        return new int[]{}; // No solution
    }

    public static void main(String[] args) {
        TwoSum obj = new TwoSum();
        int[] result = obj.twoSum(new int[]{2,7,11,15}, 9);
        System.out.println(Arrays.toString(result)); // [0,1]
    }
}
