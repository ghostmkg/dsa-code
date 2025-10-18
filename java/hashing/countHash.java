/**
 * Author: Anshul Saxena
 * Program: Count Distinct Elements in Every Window of Size K
 * Description: Uses HashMap sliding window to count distinct numbers in each window.
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 */

import java.util.*;

public class CountDistinctElementsInWindow {

    public static List<Integer> countDistinct(int[] arr, int k) {
        List<Integer> result = new ArrayList<>();
        Map<Integer, Integer> freq = new HashMap<>();

        for (int i = 0; i < k; i++)
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
        result.add(freq.size());

        for (int i = k; i < arr.length; i++) {
            freq.put(arr[i - k], freq.get(arr[i - k]) - 1);
            if (freq.get(arr[i - k]) == 0) freq.remove(arr[i - k]);
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
            result.add(freq.size());
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 3, 4, 2, 3};
        int k = 4;
        System.out.println("Distinct count per window: " + countDistinct(arr, k));
    }
}
