/* Given an integer array nums and an integer k, split nums into k non-empty subarrays such that 
the largest sum of any subarray is minimized. Return the minimized largest sum of the split. (LC 410) */

class Solution {
public:
    int no_of_partitions(vector<int>& nums, int limit){
        int partitions = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= limit)sum += nums[i];
            else {
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
          int low = INT_MIN;
          int high = 0;

          for(int i = 0; i < nums.size();i++){
            if(low < nums[i])low = nums[i];
            high += nums[i];
          }

          while(low <= high){
            int mid = low + (high - low) / 2;

            int parts = no_of_partitions(nums, mid);
            if(parts <= k)high = mid - 1;
            else low = mid + 1;
          }

          return low;
    }
};
