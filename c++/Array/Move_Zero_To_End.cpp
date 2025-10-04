// Given an integer array arr[],move all zeros to the end of the array,
// while maintaining the relative order of the non-zero elements.

#include <iostream>
#include <vector>
using namespace std;

void moveZerosToEnd(vector<int>& arr) {
    int j = 0;  // here we use j pointer for adjusting non-zero elements
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    vector<int> arr = {0,1,0,3,12};
    moveZerosToEnd(arr);
    cout << "Array after moving zeros: ";
    for (int num : arr) 
    cout<<num<<" ";
}
