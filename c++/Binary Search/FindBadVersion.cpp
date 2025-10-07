#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version) {
    return version >= 4; 
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main() {
    Solution s;
    cout << "First bad version: " << s.firstBadVersion(10);
}
