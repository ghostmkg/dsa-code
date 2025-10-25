/*
 * RadixSort.java
 *
 * Description:
 * Radix Sort is a non-comparison sorting algorithm that sorts numbers 
 * digit by digit starting from the least significant digit (LSD) to 
 * the most significant digit (MSD). It uses Counting Sort as a subroutine.
 *
 * Time Complexity: O(n * k) where k is the number of digits
 * Space Complexity: O(n + k)
 * Stable: Yes
 */

public class RadixSort {
    public static void radixSort(int[] arr) {
        if (arr.length == 0) return;

        // Find the maximum number to know number of digits
        int max = arr[0];
        for (int num : arr) {
            if (num > max) max = num;
        }

        // Apply counting sort for every digit (exp = 1, 10, 100, ...)
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSortByDigit(arr, exp);
        }
    }

    private static void countingSortByDigit(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10]; // Digits 0–9

        // Store count of occurrences for each digit
        for (int num : arr) {
            int index = (num / exp) % 10;
            count[index]++;
        }

        // Cumulative count
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array (traverse backwards for stability)
        for (int i = n - 1; i >= 0; i--) {
            int index = (arr[i] / exp) % 10;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }

        // Copy output to original array
        System.arraycopy(output, 0, arr, 0, n);
    }
}
