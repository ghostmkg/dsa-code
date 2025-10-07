/*
 * [Algorithm] : Array Deletion
 * [Author]    : tanshen-kun (Modified & documented by ChatGPT)
 *
 * Hacktoberfest2025
 */

#include <stdio.h>

// Function to delete element at given position
void array_delete(int arr[], int *size, int pos) {
    // Shift elements left from the position
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--; // Decrease array size
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);

    int pos;
    printf("Enter position to delete (0 - %d): ", size - 1);
    scanf("%d", &pos);

    // Validate position
    if (pos < 0 || pos >= size) {
        printf("Invalid position! Please enter a value between 0 and %d.\n", size - 1);
        return 1; // Exit program with error
    }

    // Perform deletion
    array_delete(arr, &size, pos);

    printf("Array After Deletion: ");
    printArray(arr, size);

    return 0;
}
