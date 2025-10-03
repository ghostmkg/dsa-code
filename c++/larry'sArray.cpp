// Larry's Array problem (HackerRank)
// approach - count inversions, check if even (YES) or odd (NO)

#include <bits/stdc++.h>
using namespace std;

string larrysArray(vector<int> arr) {
    int n = arr.size();
    int rot = 0;

    // Count inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                rot++;
        }
    }

    return (rot % 2 == 0) ? "YES" : "NO";
}

int main() {
    int n;
    cin >> n; 

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << larrysArray(arr) << "\n";
    return 0;
}
