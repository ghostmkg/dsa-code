#include <iostream>
using namespace std;

// Program to perform binary search on a sorted array
int main() {
    // Sorted array
    int A[] = {6, 8, 13, 17, 20, 22, 25, 28, 30, 35};

    // Calculate size of the array dynamically
    int n = sizeof(A) / sizeof(A[0]);

    int key;
    cout << "Enter a number to search: ";
    cin >> key;

    int low = 0, high = n - 1;

    // Binary search loop
    while (low <= high) {
        int mid = (low + high) / 2;

        if (key == A[mid]) {
            cout << "Element found at index " << mid << endl;
            return 0;
        }
        else if (key < A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << "Element not found in the array." << endl;
    return 0;
}
