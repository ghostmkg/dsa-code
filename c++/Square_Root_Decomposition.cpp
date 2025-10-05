#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
class node{
    public:
    ll n,blk;
    vector<ll>a,aux;
    void bld(){
        for(ll i=0;i<n;i++){
            aux[i/blk]+=a[i];
        } 
    }
    ll sum(ll l,ll r){
        ll bl=l/blk,br=r/blk;
        ll res=0;
        if(bl==br){
            return accumulate(a.begin()+l,a.begin()+r+1,0ll);
        }
        ll left=0;
        ll right=0;
        for(ll i=l;(i/blk)==bl;i++){
            left+=a[i];
        }
        for(ll i=bl+1;i<br;i++)res+=aux[i];
        for(ll i=br*blk;i<=r;i++){
            right+=a[i];
        }
        return res+left+right;
    }
    void upd(ll i,ll val){
        aux[i/blk]+=(val-a[i]);
        a[i]=val;
        return;
    }
    node(vector<ll>&a,ll n){
        this->n=n;
        this->a=a;
        blk=ceil(sqrt(n));
        aux=vi(blk);
        bld();
    }

};
int main(){
    ll n,q;
    cin>>n>>q;
    vi a(n);
    for(auto &i:a)cin>>i;
    node *rt=new node(a,n);
    while(q--){
        ll t,l,r;
        cin>>t;
        if(t==2){
            cin>>l>>r;
            cout<<rt->sum(l-1,r-1)<<endl;
        }
        else{
            cin>>l>>r;
            rt->upd(l-1,r);
        }
    }

}