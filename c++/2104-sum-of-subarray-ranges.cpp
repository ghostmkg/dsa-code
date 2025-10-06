#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        stack<int> st; // store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        stack<int> st; // store indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> prevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        stack<int> st; // store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        stack<int> st; // store indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }

    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev = prevSmaller(arr);
        vector<int> next = nextSmaller(arr);
        vector<int> p_g = prevGreater(arr);
        vector<int> n_g = nextGreater(arr);

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - prev[i];
            long long rightMin = next[i] - i;
            long long leftMax = i - p_g[i];
            long long rightMax = n_g[i] - i;

            minSum += (long long)arr[i] * leftMin * rightMin;
            maxSum += (long long)arr[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4,-2,-3,4,1} ; 
    int ans = sol.subArrayRanges(arr);

    
    cout << ans << endl ;

    return 0;
}
