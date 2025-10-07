// Given an array arr[] consisting only of 0s, 1s, and 2s, also Dutch National Flag Algorithm
// our task is to sort the array in ascending order
// without using any built-in sorting function otherwise this is so simple.

#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr){
    int n=arr.size();
    //creating new array
    vector<int> arrnew(n,1);

    int start=0;
    int end=n-1;

    //iterating over it
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            arrnew[start]=0;
            start++;
        }
        else if(arr[i]==2){
            arrnew[end]=2;
            end--;
        }
    }
    //copying  from newarr to old arr
    arr=arrnew;
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sort012(arr);
    cout << "Finally Sorted array: ";
    for (int num : arr)
    cout<<num<< " ";
}
