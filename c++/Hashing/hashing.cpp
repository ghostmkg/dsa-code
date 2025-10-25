#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int& i : arr) {
        cin >> i;
    }
    cout << "array inputed" << endl;

    vector<int> hash(n, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        cout << hash[num] << endl;
    }

    return 0;
}

// globally u may declare the 10^7 but in main only declare 10^6
