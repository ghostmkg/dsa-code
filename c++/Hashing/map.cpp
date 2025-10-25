#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = { 21, 5, 2, 35, 76, 8, 35, 98, 35, 66 };
    int n = arr.size();

    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    for (auto it : mpp) {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;
    while (q--) {
        int nas;
        cin >> nas;
        cout << mpp[nas] << endl;
    }

    return 0;
}