#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = { 21, 5, 2, 35, 76, 8, 35, 98, 35 };
    int n = arr.size();

    map<int, int> hash;
    // by division method unordered hashmap
    for (int i = 0; i < n; i++) {
        hash[arr[i] % 10]++;
    }

    int asa;
    cin >> asa;
    if (hash.find(asa % 10) != hash.end()) {
        cout << hash[asa] << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}