
import java.util.*;

// Rename class to JumpGame
public class JumpGame {
    // Function to compute the minimum number of jumps to reach the last index
    public int jump(int[] nums) {
        // Edge case: if array has 1 or fewer elements, no jumps needed
        if (nums == null || nums.length <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // Loop through array up to second last index
        for (int i = 0; i < nums.length - 1; i++) {
            // Update the farthest index we can reach
            farthest = Math.max(farthest, i + nums[i]);

            // If current index reaches the end of current range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                // If currentEnd has reached or passed the last index, break early
                if (currentEnd >= nums.length - 1) break;
            }
        }

        return jumps;
    }
}

// Driver Code
class JumpGameTest {
    public static void main(String[] args) {
        JumpGame sol = new JumpGame();
        int[] nums = {2, 3, 1, 1, 4};

        System.out.println("Minimum jumps required: " + sol.jump(nums));
    }
}