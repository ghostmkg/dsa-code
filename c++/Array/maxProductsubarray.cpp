#include <iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int maxProd = nums[0], minProd = nums[0], ans = nums[0];

    for (int i = 1; i < n; i++) {
        int curr = nums[i];
        if (curr < 0)
            swap(maxProd, minProd);  // because negative * negative => positive

        maxProd = max(curr, maxProd * curr);
        minProd = min(curr, minProd * curr);

        ans = max(ans, maxProd);
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << maxProduct(nums) << endl;
    return 0;
}
