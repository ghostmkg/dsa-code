#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        int leftmax = 0;
        int rightmax = 0;
        int total = 0;

        while (l < r) {
            if (arr[l] < arr[r]) {
                if (leftmax > arr[l]) {
                    total += leftmax - arr[l];
                } else {
                    leftmax = arr[l];
                }
                l++;
            } else {
                if (rightmax > arr[r]) {
                    total += rightmax - arr[r];
                } else {
                    rightmax = arr[r];
                }
                r--;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter height of bars: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = sol.trap(arr);
    cout << "Total trapped rain water: " << result << endl;

    return 0;
}
