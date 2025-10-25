#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1), output(n);

        for (int i = 1; i < n; i++) 
            left[i] = left[i - 1] * nums[i - 1];

        for (int i = n - 2; i >= 0; i--) 
            right[i] = right[i + 1] * nums[i + 1];

        for (int i = 0; i < n; i++) 
            output[i] = left[i] * right[i];

        return output;
    }
};
