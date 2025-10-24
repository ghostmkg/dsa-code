#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return total - sum;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3,0,1};
    cout << obj.missingNumber(nums) << endl; // 2
}
