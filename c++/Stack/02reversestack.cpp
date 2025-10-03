#include <bits/stdc++.h>
using namespace std;
void print (stack<int>st){
    stack<int> temp;
    while(st.size()){//  empty 
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()){// loaded stack
        cout <<temp.top()<<"  ";//normal order
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}
void PushAtBottomrec(stack<int>& st,int val){//RECURSION METHOD
    if(st.size()==0) {
        st.push(val);
        return;
    }
    int x= st.top();
    st.pop();
    PushAtBottomrec(st,val);
    st.push(x);
}
void reverseRecusion(stack<int>& st){
    if(st.size()==1) return;
    int x=st.top();
    st.pop();
    reverseRecusion(st);
    PushAtBottomrec(st,x);
}
int main(){
    stack<int> st;
    stack<int> temp1;
    stack<int> temp2;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    print(st);
    // while(st.size()){//stack method
        // temp1.push(st.top());
        // st.pop();
    // }
    // while(temp1.size()){
    // temp2.push(temp1.top());
    // temp1.pop();
    // }
    // while(temp2.size()){  
    // st.push(temp2.top());
    // temp2.pop();
    // }
    /*vector<int>v;// using vector
    while(st.size()){
    v.push_back(st.top());
    st.pop();
    }
   for(int i=0;i<v.size();i++){
     st.push(v[i]);
   }
   for(int i=0;i<v.size();i++){
     v.pop_back();
   }*/
    reverseRecusion(st);
    print(st);
}