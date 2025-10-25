#include <bits/stdc++.h>
using namespace std;

bool Rev(string& a, int l, int r)
{
    if (l >= r) {
        return true;
    }
    if (a[l] != a[r]) {
        return false;
    }
    l++;
    r--;
    return Rev(a, l, r);
}

int main()
{
    string name = "Sarthak";
    string name1 = "LooL";
    cout << boolalpha << Rev(name, 0, name.size()) << endl;
    cout << boolalpha << Rev(name1, 0, name1.size()) << endl;

    return 0;
}