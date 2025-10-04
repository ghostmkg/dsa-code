// Given an array arr[] consisting only of 0s, 1s, and 2s, also Dutch National Flag Algorithm
// our task is to sort the array in ascending order
// without using any built-in sorting function otherwise this is so simple.

#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr){
    int low=0, mid=0;
    int high = arr.size()-1;

    while (mid <= high) {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] ==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sort012(arr);
    cout << "Finally Sorted array: ";
    for (int num : arr)
    cout<<num<< " ";
}
