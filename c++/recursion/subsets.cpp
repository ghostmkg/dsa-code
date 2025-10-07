#include <iostream>
#include <vector>
using namespace std;

void solve(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        ans.push_back(current);
        return;
    }

    // Include nums[index]
    current.push_back(nums[index]);
    solve(index + 1, nums, current, ans);
    current.pop_back();

    // Exclude nums[index]
    solve(index + 1, nums, current, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    solve(0, nums, current, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3}; // you can change this input
    vector<vector<int>> result = subsets(nums);

    cout << "All subsets are:\n";
    for (auto subset : result) {
        cout << "[ ";
        for (auto x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
