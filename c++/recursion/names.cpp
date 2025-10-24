#include <bits/stdc++.h>
using namespace std;

int F(int n)
{
    if (n == 0) {
        return 0;
    }
    cout<<"Hello World"<<endl;
    return F(n - 1);
}

int main()
{
    int n = 5;
    F(n);
    return 0;
}