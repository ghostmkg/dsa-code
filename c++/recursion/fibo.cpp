#include <bits/stdc++.h>
using namespace std;

int F(int n)
{
    if (n <= 1) {
        return n;
    }
    return F(n - 1) + F(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << F(n) << endl;
    return 0;
}