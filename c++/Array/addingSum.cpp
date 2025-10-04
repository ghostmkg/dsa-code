#include <iostream>
using namespace std;

// Program to calculate the sum of all elements in an array
int main() {
    // Initialize array
    int A[] = {4, 8, 6, 9, 5, 2, 7};

    // Calculate number of elements dynamically
    int n = sizeof(A) / sizeof(A[0]);

    int sum = 0;

    // Loop through the array to calculate sum
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    // Output the result
    cout << "Sum of array elements = " << sum << endl;

    return 0;
}
