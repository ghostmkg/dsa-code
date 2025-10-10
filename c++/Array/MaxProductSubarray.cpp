// Problem: Maximum Product Subarray
// Language: C++
// Topic: Arrays / Dynamic Programming
// Description:
// Given an integer array nums, find the contiguous subarray within
// an array which has the largest product.
// Approach:
// Track both maxProd and minProd because negatives can flip the result.
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0], minProd = nums[0], result = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        result = max(result, maxProd);
    }

    return result;
}

int main() {
    /*
        Example:
        Input: [2,3,-2,4]
        Output: 6
        Explanation:
        Subarray [2,3] has the largest product = 6.
    */

    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << maxProduct(nums) << endl;

    return 0;
}
