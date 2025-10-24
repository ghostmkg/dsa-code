#include <bits/stdc++.h>
using namespace std;

int F(int n, int h)
{
    if (n == 0) {
        return 0;
    }
    F(n - 1, h);
    cout << n << endl;
}

int main()
{
    int n;

    cout << "Enter the Number:";
    cin >> n;
    int h = n;
    F(n, h);
    return 0;
}