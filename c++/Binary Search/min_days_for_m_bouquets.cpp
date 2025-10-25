#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& arr, int day, int n, int m, int k) {   
        int count = 0;
        int no_of_bouquet = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                count++;
            } else {
                no_of_bouquet += (count / k);
                count = 0;
            }
        }
        no_of_bouquet += (count / k);
        return no_of_bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();  
        int minday = INT_MAX;
        int maxday = INT_MIN;
        for (int i = 0; i < n; i++) {
            minday = min(minday, bloomDay[i]);
            maxday = max(maxday, bloomDay[i]);
        }  

        // if total flowers < total needed flowers
        if (n < (long long)m * k) return -1;

        int low = minday;
        int high = maxday;
        int ans = maxday;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, n, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, m, k;
    cout << "Enter number of flowers (n): ";
    cin >> n;
    cout << "Enter number of bouquets (m): ";
    cin >> m;
    cout << "Enter flowers per bouquet (k): ";
    cin >> k;

    vector<int> bloomDay(n);
    cout << "Enter bloom days of each flower: ";
    for (int i = 0; i < n; i++) {
        cin >> bloomDay[i];
    }

    Solution sol;
    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum number of days required: " << result << endl;
    return 0;
}
