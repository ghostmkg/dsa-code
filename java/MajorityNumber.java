import java.util.*;

//This is  Morris algorithm with O(n) time complexity and O(1) space complexity
public class MajorityNumber {
     
    public static int majorityElement(int[] nums) {
        int candidate = 0, count = 0;

       //Find candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

       
        count = 0;
        for (int num : nums) {
            if (num == candidate) count++;
        }
        return count > nums.length / 2 ? candidate : -1; // -1 means no majority
    }

    public static void main(String[] args) {
        int[] nums = {2, 2, 1, 1, 1, 2, 2};
        System.out.println("Majority Element = " + majorityElement(nums));
    }


}
