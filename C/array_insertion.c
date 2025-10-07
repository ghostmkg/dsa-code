/*
 *
 * [Algorithm] : Array Insertion
 * [Author]    : tanshen-kun (Improved and documented by ChatGPT)
 *
 * Hacktoberfest2025
 */

#include <stdio.h>

// Function to insert an element into the array
void array_insert(int arr[], int *size, int value, int pos) {
    // Shift elements to the right
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value; // Insert new element
    (*size)++;         // Increase size
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50] = {1, 3, 4, 5, 6, 7, 8, 9}; // Initial array
    int size = 8;

    printf("Original Array: ");
    printArray(arr, size);

    int pos, value;

    printf("Enter the position to insert (0 to %d): ", size);
    scanf("%d", &pos);

    // Validate position
    if (pos < 0 || pos > size) {
        printf("Invalid position! Please enter a value between 0 and %d.\n", size);
        return 1;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    array_insert(arr, &size, value, pos);

    printf("Array After Insertion: ");
    printArray(arr, size);

    return 0;
}
