#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, farthest = 0, curr_end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == curr_end) {
                jumps++;
                curr_end = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = obj.jump(nums);
    cout << "Minimum number of jumps: " << result << endl;

    return 0;
}
