#include <bits/stdc++.h>
using namespace std;
vector<int> two_sum(vector<int>& v, int t) {
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++){
        if(m.count(t-v[i])) return {m[t-v[i]],i};
        m[v[i]]=i;
    }
    return {};
}
int main(){
    vector<int> v={2,7,11,15};
    int t=9;
    auto r=two_sum(v,t);
    for(int x:r) cout<<x<<" ";
}
