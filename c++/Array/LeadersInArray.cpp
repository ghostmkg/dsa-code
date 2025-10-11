// Problem: Leaders in an Array
// Language: C++
// Topic: Arrays / Traversal / Optimization
// Description:
// A leader in an array is an element that is greater than all elements to its right.
// The rightmost element is always a leader.
// Approach:
// Traverse the array from right to left, keep track of the maximum element so far.
// If the current element is greater than or equal to max_so_far, it’s a leader.
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n) {
    vector<int> ans;
    int max_from_right = arr[n - 1];
    ans.push_back(max_from_right);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= max_from_right) {
            max_from_right = arr[i];
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    /*
        Example:
        Input: arr[] = {16, 17, 4, 3, 5, 2}
        Output: 17 5 2
        Explanation: 
        Leaders are elements greater than all elements to their right.
    */

    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res = leaders(arr, n);

    cout << "Leaders in the array: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
