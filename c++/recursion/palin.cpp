#include <bits/stdc++.h>
using namespace std;

bool Rev(string& a, int i = 0)
{
    int n = a.size();
    if (i >= n / 2) {
        return true;
    }
    if (a[i] != a[n - i - 1]) {
        return false;
    }
    i++;
    return Rev(a, i);
}

int main()
{
    string name = "Sarthak";
    string name1 = "LooL";
    cout << boolalpha << Rev(name) << endl;
    cout << boolalpha << Rev(name1) << endl;

    return 0;
}