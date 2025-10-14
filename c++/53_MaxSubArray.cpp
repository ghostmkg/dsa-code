class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
        int n=nums.size();

    for (int i = 0; i < n; i++) {

        sum += nums[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
    }
};