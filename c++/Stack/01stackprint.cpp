#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> st;
    stack<int> temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    // while(st.size()){//empty of 
    // cout <<endl<<st.top();
    // st.pop();
    // }
    while(st.size()){//  empty 
        cout <<st.top()<<endl;//reverse order
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()){// loaded stack
        cout <<temp.top()<<endl;//normal order
        st.push(temp.top());
        temp.pop();
    }
}