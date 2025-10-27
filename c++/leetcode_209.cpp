// Minimum Size Subarray Sum
// Leetcode Profile: https://leetcode.com/The_STK/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, sum = 0, minLen = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << minSubArrayLen(target, nums);
}
