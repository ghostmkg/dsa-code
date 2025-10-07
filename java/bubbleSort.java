import java.util.Arrays;
import java.util.Scanner;

/**
 * A class containing the implementation of the Bubble Sort algorithm.
 */
public class bubbleSort {

    /**
     * Sorts an array using the bubble sort algorithm.
     *
     * @param arr The array to be sorted.
     */
    public void sort(int[] arr) {
        if (arr == null || arr.length == 0) {
            return;
        }

        int n = arr.length;
        boolean swapped;
        // The outer loop runs from the first element to the second-to-last element.
        // After each pass of the outer loop, the largest unsorted element "bubbles up" to its correct position.
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            // The inner loop compares adjacent elements and swaps them if they are in the wrong order.
            // The range of the inner loop decreases with each pass of the outer loop, as the largest elements are already in place.
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            // If no two elements were swapped by the inner loop, then the array is sorted.
            if (!swapped) {
                break;
            }
        }
    }

    /**
     * The main method to demonstrate the bubble sort functionality interactively.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BubbleSort sorter = new BubbleSort();

        System.out.println("--- Interactive Bubble Sort ---");
        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        if (n <= 0) {
            System.out.println("Array size must be positive. Exiting.");
            scanner.close();
            return;
        }

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            System.out.print("Element " + (i + 1) + ": ");
            arr[i] = scanner.nextInt();
        }

        System.out.println("\nOriginal array: " + Arrays.toString(arr));

        sorter.sort(arr);

        System.out.println("Sorted array:   " + Arrays.toString(arr));

        scanner.close();
    }
}
