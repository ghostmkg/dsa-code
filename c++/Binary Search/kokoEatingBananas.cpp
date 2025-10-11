#include <bits/stdc++.h>
using namespace std;

// Function to check if Koko can finish at speed "speed"
bool canEat(vector<int>& piles, int h, int speed) {
    long long hours = 0;
    for (int p : piles) {
        hours += (p + speed - 1) / speed; // ceil division
    }
    return hours <= h;
}

// Binary search to find minimum eating speed
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canEat(piles, h, mid))
            high = mid;  // try smaller speed
        else
            low = mid + 1; // need higher speed
    }
    return low;
}

// Driver code for VS Code
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter the number of bananas in each pile: ";
    for (int i = 0; i < n; i++)
        cin >> piles[i];

    cout << "Enter total hours Koko has: ";
    cin >> h;

    int minSpeed = minEatingSpeed(piles, h);
    cout << "Minimum eating speed Koko needs: " << minSpeed << "\n";

    return 0;
}
