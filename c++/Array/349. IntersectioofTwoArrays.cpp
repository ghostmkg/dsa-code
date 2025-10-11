#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> nums1_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums1_set.count(num) > 0) {
                result.push_back(num);
                nums1_set.erase(num); 
            }
        }
        return result;
    }
};





