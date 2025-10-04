#include <iostream>
using namespace std;

// Program to perform linear search in an array
int main() {
    const int n = 10;
    int A[n];
    int key;

    // Input array elements
    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Input key to search
    cout << "Enter the number to search: ";
    cin >> key;

    // Linear search logic
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            cout << "Element found at index: " << i << endl;
            return 0;
        }
    }

    // If not found
    cout << "Element not found in the array." << endl;
    return 0;
}
