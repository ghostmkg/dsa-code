#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
    ans.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates
        if (i > index && nums[i] == nums[i - 1])
            continue;

        current.push_back(nums[i]);
        solve(i + 1, nums, current, ans);
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort first
    vector<vector<int>> ans;
    vector<int> current;
    solve(0, nums, current, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2}; // you can change this input
    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "All unique subsets are:\n";
    for (auto subset : result) {
        cout << "[ ";
        for (auto x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
