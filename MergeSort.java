import java.util.Arrays;

public class MergeSort {

    /**
     * The main function that sorts arr[l...r] using merge()
     * This is the recursive "divide" part.
     *
     * @param arr   The array to be sorted
     * @param left  The starting index
     * @param right The ending index
     */
    public void sort(int arr[], int left, int right) {
        if (left < right) {
            // Find the middle point
            int middle = (left + right) / 2;

            // Recursively sort the first and second halves
            sort(arr, left, middle);
            sort(arr, middle + 1, right);

            // Merge the sorted halves
            merge(arr, left, middle, right);
        }
    }

    /**
     * Merges two subarrays of arr[].
     * First subarray is arr[left...middle]
     * Second subarray is arr[middle+1...right]
     * This is the "conquer" part.
     *
     * @param arr    The original array
     * @param left   The starting index of the first subarray
     * @param middle The ending index of the first subarray
     * @param right  The ending index of the second subarray
     */
    void merge(int arr[], int left, int middle, int right) {
        // Find sizes of two subarrays to be merged
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // --- Create temporary arrays ---
        int L[] = new int[n1];
        int R[] = new int[n2];

        // --- Copy data to temp arrays ---
        for (int i = 0; i < n1; ++i) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = arr[middle + 1 + j];
        }

        // --- Merge the temp arrays ---

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of the merged subarray in the original array
        int k = left;
        
        // Compare elements from L and R and place the smaller one into arr
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

        // --- Copy remaining elements (if any) ---
        
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
     * A main method to test the merge sort implementation.
     */
    public static void main(String args[]) {
        int arr[] = { 12, 11, 13, 5, 6, 7 };

        System.out.println("Original array:");
        System.out.println(Arrays.toString(arr));

        MergeSort ob = new MergeSort();
        ob.sort(arr, 0, arr.length - 1);

        System.out.println("\nSorted array:");
        System.out.println(Arrays.toString(arr));
    }
}
