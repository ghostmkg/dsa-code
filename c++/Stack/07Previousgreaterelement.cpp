#include <bits/stdc++.h>
using namespace std;
int main(){
   int arr[]={100,80,60,81,70,60,75,85};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int pge[n];
    stack<int>st;//stack 
    pge[0]=-1;
    st.push(arr[0]);
    for(int i=1;i<=n-1;i++){
        //pop all the elements similar than arr[i]
        while(st.size()>0 && st.top()<=arr[i]) st.pop();
        //mark the ans in the nge array
        if(st.size()==0) pge[i]=-1;
        else pge[i]=st.top();
        //push the arr[i]
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<pge[i]<<" ";
    }
}