#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 0, high = n, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long coins = mid * (mid + 1) / 2;

            if (coins == n) {
                return mid;
            }
            else if (coins < n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of coins: ";
    cin >> n;
    cout << "Full rows formed: " << sol.arrangeCoins(n) << endl;
    return 0;
}
