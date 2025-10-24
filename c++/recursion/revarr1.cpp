#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr);

void Rev(int& i, vector<int>& a, int& n)
{
    if (i >= n / 2) {
        return;
    }
    swap(a[i], a[n - i - 1]);
    i++;
    Rev(i, a, n);
}

int main()
{
    vector<int> arr = { 3, 2, 31, 45, 14 };
    printArr(arr);
    int i = 0, n = arr.size();
    Rev(i, arr, n);
    printArr(arr);
    return 0;
}
void printArr(vector<int> arr)
{
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}