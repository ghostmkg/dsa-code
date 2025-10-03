import java.util.*;

public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        //using hashset sometimes faster than using two pointers
        Set<List<Integer>> result = new HashSet<>();
        int n  = nums.length;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

           Set<Integer> s = new HashSet<>();
           for(int j = i+1; j<n; j++){
            int complement = -nums[i] - nums[j];
            if(s.contains(complement)){
                result.add(Arrays.asList(nums[i], complement, nums[j]));
            }
            s.add(nums[j]);
           }
        }

        return new ArrayList<>(result);
    }

    public static void main(String[] args) {
        ThreeSum obj = new ThreeSum();
        System.out.println(obj.threeSum(new int[]{-1,0,1,2,-1,-4}));
        // [[-1,-1,2], [-1,0,1]]
    }
}
