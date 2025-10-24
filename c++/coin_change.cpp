#include <bits/stdc++.h>
using namespace std;
int coin_change(vector<int>& c,int a){
    vector<int> d(a+1,1e9);
    d[0]=0;
    for(int x:c){
        for(int i=x;i<=a;i++) d[i]=min(d[i],d[i-x]+1);
    }
    return d[a]==1e9?-1:d[a];
}
int main(){
    vector<int> c={1,2,5};
    int a=11;
    cout<<coin_change(c,a);
}
