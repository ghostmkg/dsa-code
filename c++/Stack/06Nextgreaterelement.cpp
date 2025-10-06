#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,4,8,3,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
     int nge[n];
    // for(int i=0;i<n;i++){
    //     nge[i]=-1;
    //     for(int j=i+1;j<n;j++){ 
    //         if(arr[j]>arr[i]){
    //             nge[i]=arr[j];
    //             break;
    //         }
    //     }
    // }


    stack<int>st;//stack 
    nge[n-1]=-1;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        //pop all the elements similar than arr[i]
        while(st.size()>0 && st.top()<=arr[i]) st.pop();
        //mark the ans in the nge array
        if(st.size()==0) nge[i]=-1;
        else nge[i]=st.top();
        //push the arr[i]
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
}