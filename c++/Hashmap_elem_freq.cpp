#include <iostream>

using namespace std;

// Problem Statement: Given an int array of size N. Find the highest and lowest frequency element.

// Example 1:
// Input: array[] = {10,5,10,15,10,5};
// Output: 10 15
// Explanation: The frequency of 10 is 3, i.e. the highest and the frequency of 15 is 1 i.e. the lowest.

void unorderedMapIntFreq(int n, int arr[])
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    int small = INT_MAX, large = INT_MIN;
    int l_el, s_el;
    for (auto it : mpp)
    {
        if (it.second > large)
        {
            large = it.second;
            l_el = it.first;
        }
        if (it.second < small)
        {
            small = it.second;
            s_el = it.first;
        }
    }
    cout << l_el << ": " << large << endl;
    cout << s_el << ": " << small << endl;
}

int main()
{

    int arr[] = {3, 2, 1, 3, 2, 1, 4, 5, 3, 2, 5, 4, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    unorderedMapIntFreq(n, arr);
    return 0;
}

// Output:
// 2: 3
// 13: 1