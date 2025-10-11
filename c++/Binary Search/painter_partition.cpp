// Problem: Painter Partition - Find the minimum time to paint n boards with k painters
// Given an array of board lengths, each painter paints contiguous boards, minimize the max time any painter takes.
#include <bits/stdc++.h>
using namespace std;

bool canPaint(vector<int>& boards, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;
    for (int board : boards) {
        if (currTime + board <= maxTime) {
            currTime += board;
        } else {
            painters++;
            currTime = board;
            if (board > maxTime) return false;
        }
    }
    return painters <= k;
}

int painterPartition(vector<int>& boards, int k) {
    int n = boards.size();
    if (n < k) return -1; // Not enough boards for painters
    int left = *max_element(boards.begin(), boards.end());
    int right = accumulate(boards.begin(), boards.end(), 0);
    int result = INT_MAX;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPaint(boards, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> boards = {1, 5, 5, 10};
    int k = 2;
    cout << painterPartition(boards, k) << endl; // Output: 10
    return 0;
}