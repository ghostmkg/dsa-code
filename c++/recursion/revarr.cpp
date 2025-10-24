#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr);

void Rev(vector<int>& a, int& l, int& r)
{
    if (l >= r) {
        return;
    }
    swap(a[l], a[r]);
    l++;
    r--;
    Rev(a, l, r);
}

int main()
{
    vector<int> arr = { 3, 2, 31, 45, 14 };
    printArr(arr);
    int l = 0;
    int r = arr.size() - 1;
    Rev(arr, l, r);
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