#include <iostream>
using namespace std;
// Brute force solution TLE TC = O(n)
int arrangeCoinsBruteI(int n)
{
    int row = 0;
    int coin = 0;
    for (int i = 1; i <= n; i++)
    {
        coin += i;
        if (coin <= n)
            row++;
    }
    return row;
}
// Brute force solution TC = O(n) wast case
int arrangeCoinsBruteII(int n)
{
    int coin = n;
    for(int i = 1; i < n; i++){
        coin -= i;
        if(coin == 0) return i;
        if(coin < 0) return i - 1;
    }
    return -1;
}
// Optimal solution I = TLE TC = O(1)
int arrangeCoinsOptimalI(int n)
{
    int k = (sqrt((8 * n) + 1) - 1) / 2;

    return k;
}
// Optimal solution II
int arrangeCoinsOptimalII(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = (mid * (mid + 1)) / 2;
        if(val == n) return mid;
        if(val > n) high = mid - 1;
        else low = mid + 1;
    }

    return high;
}
int main()
{
    cout << "arrange Coins : " << arrangeCoinsBruteI(5) << endl;
    cout << "arrange Coins : " << arrangeCoinsBruteII(5) << endl;
    cout << "arrange Coins : " << arrangeCoinsOptimalI(5) << endl;
    cout << "arrange Coins : " << arrangeCoinsOptimalII(5) << endl;

    return 0;
}