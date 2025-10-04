/**
 * MergeSort.java
 *
 * Implementation of Merge Sort algorithm in Java.
 * 
 * Merge Sort is a classic Divide and Conquer algorithm that:
 * 1. Divides the array into two halves.
 * 2. Recursively sorts both halves.
 * 3. Merges the two sorted halves into a single sorted array.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 *
 * Author: Pushpak M. Jaiswal
 * Date: October 2025
 */

package algorithms.sorting;

import java.util.Arrays;

public class MergeSort {

    /**
     * Main mergeSort function — recursively divides the array
     * and merges the sorted halves.
     *
     * @param arr the array to be sorted
     * @param left starting index
     * @param right ending index
     */
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            // Find the middle index
            int mid = (left + right) / 2;

            // Recursively sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

    /**
     * Helper function to merge two sorted subarrays.
     * Subarray 1: arr[left..mid]
     * Subarray 2: arr[mid+1..right]
     *
     * @param arr the array being sorted
     * @param left starting index
     * @param mid middle index
     * @param right ending index
     */
    private static void merge(int[] arr, int left, int mid, int right) {
        // Find sizes of two subarrays to be merged
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays
        int[] L = new int[n1];
        int[] R = new int[n2];

        // Copy data to temp arrays
        for (int i = 0; i < n1; ++i)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[mid + 1 + j];

        // Merge the temp arrays back into arr[left..right]
        int i = 0, j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[] if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[] if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    /**
     * Utility function to print arrays in readable format.
     */
    private static void printArray(String msg, int[] arr) {
        System.out.println(msg + Arrays.toString(arr));
    }

    /**
     * Main method containing sample test cases.
     */
    public static void main(String[] args) {
        // 1. Small Array
        int[] smallArray = {38, 27, 43, 3, 9, 82, 10};
        mergeSort(smallArray, 0, smallArray.length - 1);
        printArray("Sorted Small Array: ", smallArray);

        // 2. Large Array
        int[] largeArray = new int[20];
        for (int i = 0; i < 20; i++) {
            largeArray[i] = (int) (Math.random() * 100);
        }
        mergeSort(largeArray, 0, largeArray.length - 1);
        printArray("Sorted Large Array: ", largeArray);

        // 3. Already Sorted Array
        int[] sortedArray = {1, 2, 3, 4, 5, 6, 7};
        mergeSort(sortedArray, 0, sortedArray.length - 1);
        printArray("Already Sorted Array: ", sortedArray);

        // 4. Reverse-Sorted Array
        int[] reverseArray = {9, 7, 5, 3, 1};
        mergeSort(reverseArray, 0, reverseArray.length - 1);
        printArray("Reverse-Sorted Array: ", reverseArray);
    }
}
