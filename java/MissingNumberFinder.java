import java.util.Scanner;

public class MissingNumberFinder {

    // Function to find the missing number
    public static int missingNumber(int[] nums) {
        int n = nums.length;
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Example: Enter array elements separated by space: 3 0 1
        System.out.println("Enter array elements separated by space:");
        String[] input = sc.nextLine().trim().split(" ");
        int[] nums = new int[input.length];

        for (int i = 0; i < input.length; i++) {
            nums[i] = Integer.parseInt(input[i]);
        }

        int result = missingNumber(nums);
        System.out.println("Missing Number is: " + result);

        sc.close();
    }
}
