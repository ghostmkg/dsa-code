#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        //finding the potential candidate
        for (int num : nums) {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }

       //Verifying the candidate
        int freq = 0;
        for (int num : nums) {
            if (num == candidate)
                freq++;
        }

        // If needed, verify it's truly majority
        if (freq > nums.size() / 2)
            return candidate;
        else
            return -1; // no majority element found
    }
};

int main() {
    Solution sol;

    // example 
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int result = sol.majorityElement(nums);

    if (result != -1)
        cout << "Majority Element: " << result << endl;
    else
        cout << "No Majority Element found." << endl;

    return 0;
}
