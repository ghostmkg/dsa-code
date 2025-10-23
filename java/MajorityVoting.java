import java.util.*;

class MajorityElementFinder {

  public static int findMajority(int[] nums) {
    int count = 0, candidate = -1;

    for (int index = 0; index < nums.length; index++) {
      if (count == 0) {
        candidate = nums[index];
        count = 1;
      } else {
        if (nums[index] == candidate)
          count++;
        else
          count--;
      }
    }

    count = 0;
    for (int index = 0; index < nums.length; index++) {
      if (nums[index] == candidate)
        count++;
    }
    if (count > (nums.length / 2))
      return candidate;
    return -1;
  }

  public static void main(String[] args) {
    int arr[] = { 1, 1, 1, 1, 2, 3, 4 };
    int majority = findMajority(arr);
    System.out.println("The majority element is: " + majority);
  }
}
