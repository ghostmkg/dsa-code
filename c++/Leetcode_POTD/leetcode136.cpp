#include<iostream>
using namespace std;

int findsingle(int arr[], int n){
    int ans=0;
    int count=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
        count =count+1;

    }
    return ans  ;
    cout<<count;
}

int main() {
 // single no in an array where every no is present twice


 int arr[] = {1,2,3,4,1,2,3};
 int n= sizeof(arr)/sizeof(arr[0]);
 int ans =findsingle(arr,n);
 cout<<ans;
 



return 0;
}