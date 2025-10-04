class Solution {
public:
    bool isPossible(vector<int>& arr, int n, int m, int mid) {
        int studentCount = 1;
        int pageSum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) return false;
            if (pageSum + arr[i] > mid) {
                studentCount++;
                pageSum = arr[i];
                if (studentCount > m) return false;
            } else {
                pageSum += arr[i];
            }
        }
        return true;
    }

    int allocateBooks(vector<int>& arr, int m) {
        int n = arr.size();
        if (m > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, n, m, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
