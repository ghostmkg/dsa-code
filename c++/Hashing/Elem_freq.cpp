#include <iostream>
using namespace std;

// Problem Statement: Given an array nums of size n which may contain duplicate elements, return a list of pairs where each pair contains a unique element from the array and its frequency in the array.

// Input : [1,2,3,3,2,2,5]
// Output: [[1,1],[2,3],[3,2],[5,1]]

void intHash(int n, int arr[])
{
    //  Hashing for numbers in an array
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (hash[i] > 0)
        {
            cout << "[" << i << ", " << hash[i] << "], ";
        }
    }
    cout << "]" << endl;
}

int main()
{

    int arr[] = {3, 2, 1, 3, 2, 1, 4, 5, 3, 2, 5, 4, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    intHash(n, arr);
    return 0;
}
