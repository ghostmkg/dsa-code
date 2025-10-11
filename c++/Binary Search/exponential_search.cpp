// Problem: Exponential Search - Find the index of a target in a sorted array
// Uses exponential bounding followed by binary search. Ideal for large/unbounded sorted arrays.
// Time Complexity: O(log n) average case.
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int target) {
    int n = arr.size();
    if (n == 0) return -1;
    if (arr[0] == target) return 0;

    // Find the bound exponentially
    int i = 1;
    while (i < n && arr[i] < target) {
        i *= 2; // Double the index
    }

    // Binary search in the found range
    return binarySearch(arr, i / 2, min(i, n - 1), target);
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40, 50, 60, 70, 80};
    int target = 40;
    int result = exponentialSearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl; // Output: Element found at index: 3
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}