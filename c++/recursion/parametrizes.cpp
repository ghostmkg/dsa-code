#include <bits/stdc++.h>
using namespace std;

int F(int n, int sum = 0)
{
    if (n == 0) {
        return sum;
    }
    return F((n - 1), sum + (n));
}

int main()
{
    int n;
    cin >> n;
    cout << F(n, 0) << endl;
    return 0;
}