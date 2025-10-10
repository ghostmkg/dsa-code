
// Problem Statement:
// Given an integer array arr[] and an integer k, find the length of the longest subarray whose sum equals k.

#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Longest Subarray with Sum K
 * Approach: Prefix Sum + HashMap
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    unordered_map<int, int> prefixIndex; // prefixSum -> first index
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Case 1: Subarray from 0 to i has sum k
        if (prefixSum == k)
            maxLen = i + 1;

        // Case 2: Check if (prefixSum - k) exists
        if (prefixIndex.find(prefixSum - k) != prefixIndex.end()) {
            int len = i - prefixIndex[prefixSum - k];
            maxLen = max(maxLen, len);
        }

        // Store prefixSum's first occurrence
        if (prefixIndex.find(prefixSum) == prefixIndex.end())
            prefixIndex[prefixSum] = i;
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << "Longest subarray length = " << longestSubarrayWithSumK(arr, k) << endl;
    return 0;
}
