#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(vector<int>& arr, int target) {
    int left = 0;                 // Starting index of the search range
    int right = arr.size() - 1;   // Ending index of the search range

    // Continue searching until the range is valid
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow from (left + right)/2

        if (arr[mid] == target) { // If the middle element matches the target
            return mid;           // Return the index where target is found
        } 
        else if (arr[mid] < target) {
            left = mid + 1;       // Search in the right half
        } 
        else {
            right = mid - 1;      // Search in the left half
        }
    }

    return -1; // If not found, return -1
}

int main() {
    // Input sorted array
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};

    // Element to search for
    int target = 10;

    // Call binary search function
    int result = binarySearch(arr, target);

    // Display result
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0; // Successful program termination
}
