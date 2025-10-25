#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // O(log(n))->time
        int n=arr.size();
        int l=0,r=n-1,mid;
        while(l<r){
            mid=(l+r)/2;
            if(arr[mid]<arr[mid+1]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;



        //O(n)->time
        // int idx=0;
        // for(int i=1;i<arr.size();i++){
        //     if(arr[i]>arr[i-1]){
        //         idx=i;
        //     }
        // }
        // return idx;
    }
};