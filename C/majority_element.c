// majority_element.c
// Find the majority element in an array using Boyer-Moore Voting Algorithm
#include <stdio.h>

int findMajorityElement(int arr[], int n) {
    int count = 0, candidate = -1;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    // Verify candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) count++;
    }
    if (count > n / 2) return candidate;
    return -1;
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = findMajorityElement(arr, n);
    if (result != -1)
        printf("Majority element is %d\n", result);
    else
        printf("No majority element found.\n");
    return 0;
}
