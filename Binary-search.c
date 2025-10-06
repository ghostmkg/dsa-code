#include <stdio.h>

// Function for Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;  // find middle index

        if (arr[mid] == target)
            return mid; // element found, return its index
        else if (arr[mid] < target)
            low = mid + 1; // search right half
        else
            high = mid - 1; // search left half
    }

    return -1; // element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
