#include <iostream>
using namespace std;

// Function to find the integer square root of x
int sqrtBinarySearch(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid*mid is equal to x
        if (mid <= x / mid) {  // To avoid overflow
            ans = mid;         // mid is a possible answer
            left = mid + 1;    // try to find a bigger one
        } else {
            right = mid - 1;   // mid*mid > x, go smaller
        }
    }

    return ans;
}

int main() {
    int x = 17;
    cout << "Integer square root of " << x << " is " << sqrtBinarySearch(x) << endl;
    return 0;
}
