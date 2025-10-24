#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ls = "askbanbcma";
    int n = ls.size();
    vector<int> hash(26, 0); // this is constant mapping array such that it stored the mapped elements
    for (char c : ls) {
        hash[c - 'a'] += 1;
    }

    char as;
    cin >> as;
    cout << hash[as - 'a'] << endl;

    return 0;
}

// at max there are 256 characters so max hash size is 256
// ch - 'A'
// ch - 'a'