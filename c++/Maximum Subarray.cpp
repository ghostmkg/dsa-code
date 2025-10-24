#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurrent = nums[0], maxGlobal = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxCurrent = max(nums[i], maxCurrent + nums[i]);
            maxGlobal = max(maxGlobal, maxCurrent);
        }
        return maxGlobal;
    }
};
