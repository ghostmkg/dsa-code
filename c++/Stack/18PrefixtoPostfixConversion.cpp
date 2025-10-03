#include <bits/stdc++.h>
using namespace std;
string solve(string val1,string val2,char ch){
    string s="";
    s+=val1;
    s+=val2;
    s.push_back(ch);
    return s;
}
int main(){
    string s="-/*+79483";//prefix expression
    //we need two stacksc 1 for vals,1 for ops
    stack<string> val;
     for(int i=s.length()-1;i>=0;i--){
        //check if s[i] is a digit
        if(s[i]>=48 && s[i]<=57){//digit
        val.push(to_string(s[i]-'0'));
        }
        else{//s[i]->*/-+ ( )
            string val1=val.top();
            val.pop();
            string val2=val.top();
            val.pop();
            string ans=solve(val1,val2,s[i]);
            val.push(ans);
        }
    } 
    cout<< val.top()<<endl;
    cout<<"79+4*8/3-";
}