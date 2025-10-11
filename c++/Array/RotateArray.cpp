// Problem: Rotate Array by K Steps
// Language: C++
// Topic: Arrays / Rotation / Reversal
// Description:
// Given an integer array and a number K, rotate the array to the right by K steps.
// Approach:
// Reverse entire array, then reverse first K and remaining N-K parts individually.
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start++], arr[end--]);
    }
}

void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // In case k > n

    // Reverse steps
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
}

int main() {
    /*
        Example:
        Input: arr = [1, 2, 3, 4, 5, 6, 7], k = 3
        Output: [5, 6, 7, 1, 2, 3, 4]
        Explanation:
        After rotating by 3 steps, last 3 elements come to the front.
    */

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original Array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    rotate(arr, k);

    cout << "Array after rotation by " << k << " steps: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
