#include <stdio.h>

int main() {
    int n, sum = 0;

    // Ask user for number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Add each element to sum
    }

    // Display the sum
    printf("The sum of the elements is: %d\n", sum);

    return 0;
}
