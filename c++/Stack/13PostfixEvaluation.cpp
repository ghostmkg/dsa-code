#include <bits/stdc++.h>
using namespace std;
int solve(int val1,int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else if(ch=='/') return val1/val2;
}
int main(){
    string s="79+4*8/3-";//postfix expression
    //we need one stacks 1 for vals
    stack<int> val;
    for(int i=0;i<s.length();i++){
        //check if s[i] is a digit
        if(s[i]>=48 && s[i]<=57){//digit
        val.push(s[i]-'0');
        }
        else{//s[i]->*/-+ ( )
            int val2=val.top();
            val.pop();
            int val1=val.top();
            val.pop();
            int ans=solve(val1,val2,s[i]);
            val.push(ans);
       }
    }
    cout<< val.top()<<endl;
    cout<<(7+9)*4/8-3;
}