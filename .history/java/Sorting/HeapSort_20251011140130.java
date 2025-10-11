package Sorting;

public class HeapSort {

    // Function to heapify a subtree rooted with node i
    static void heapify(int arr[], int n, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left child index
        int right = 2 * i + 2; // right child index

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    // Main function to perform heap sort
    static void heapSort(int arr[]) {
        int n = arr.length;

        // Step 1: Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Step 2: Extract elements one by one
        for (int i = n - 1; i >= 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    // Utility function to print array
    static void printArray(int arr[]) {
        for (int value : arr)
            System.out.print(value + " ");
        System.out.println();
    }

    // Driver code
    public static void main(String args[]) {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        System.out.println("Original array:");
        printArray(arr);

        heapSort(arr);

        System.out.println("Sorted array:");
        printArray(arr);
    }
}
