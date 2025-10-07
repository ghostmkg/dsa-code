#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a maximum time 'mid' is possible with k painters
bool isPossible(const vector<int>& boards, int k, int mid) {
    int painters = 1;
    int time = 0;

    for (int length : boards) {
        if (length > mid) return false; // Cannot paint a board larger than mid
        if (time + length > mid) {
            painters++;     // Need a new painter
            time = length;  // Start new painter with current board
        } else {
            time += length; // Add board to current painter
        }
    }

    return painters <= k; // True if painters used <= k
}

// Function to find minimum time to paint all boards
int painterPartition(const vector<int>& boards, int k) {
    int left = *max_element(boards.begin(), boards.end()); // At least largest board
    int right = 0;
    for (int len : boards) right += len; // At most sum of all boards
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(boards, k, mid)) {
            result = mid;      // Mid is a possible solution
            right = mid - 1;   // Try to minimize further
        } else {
            left = mid + 1;    // Increase time
        }
    }

    return result;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2; // Number of painters

    int minTime = painterPartition(boards, k);

    cout << "Minimum time to paint all boards: " << minTime << endl;

    return 0;
}
