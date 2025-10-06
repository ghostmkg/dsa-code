#include <bits/stdc++.h>
using namespace std;
void display( queue<int>& q){
    int n=q.size();
    for(int i=1;i<=n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void revevesek(int k,queue<int>& q){
    int n=q.size();
    stack<int>st;
    for(int i=1;i<=k;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    for(int i=1;i<=n-k;i++){
        q.push(q.front());
        q.pop();
    }

}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    display(q);
    int k=8;
    revevesek(k,q);
    display(q);
}