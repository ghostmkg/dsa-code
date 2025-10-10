// Problem: Find Missing Number in Array
// Language: C++
// Topic: Arrays / Math / XOR
// Description:
// Given an array containing N distinct numbers taken from 0 to N,
// find the one number that is missing from the array.
// Approach:
// Use XOR of all numbers from 0 to N and XOR of all array elements.
// Missing number = XOR(0..N) XOR XOR(all elements).
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++) {
        xor1 ^= nums[i];
        xor2 ^= i + 1; // XOR of 1..N
    }

    return xor1 ^ xor2;
}

int main() {
    /*
        Example:
        Input: [3, 0, 1]
        Output: 2
        Explanation:
        Numbers in range [0,3] are 0,1,2,3. Missing number is 2.
    */

    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << missingNumber(nums) << endl;

    return 0;
}
