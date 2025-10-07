/*
                            Problem Statemnet
                            B. Deck of Cards
                        time limit per test2 seconds
                    memory limit per test256 megabytes
Monocarp has a deck of cards numbered from 1
 to 𝑛
. Initially, the cards are arranged from smallest to largest, with 1
 on top and 𝑛
 at the bottom.

Monocarp performed 𝑘
 actions on the deck. Each action was one of three types:

remove the top card;
remove the bottom card;
remove either the top or bottom card.
Your task is to determine the fate of each card: whether it remains in the deck, has been removed, or might be both.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛≤2⋅105
).

The second line contains a string 𝑠
 of length 𝑘
, consisting of characters 0, 1, and/or {2}. This string describes Monocarp's actions. If the 𝑖
-th character is 0, Monocarp removes the top card on the 𝑖
-th action. If it's 1, he removes the bottom card. If it's 2, either the top or bottom card can be removed.

Additional constraint on the input: the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print a string consisting of 𝑛
 characters. The 𝑖
-th character should be + (plus sign) if the 𝑖
-th card is still in the deck, - (minus sign) if it has been removed, or ? (question mark) if its state is unknown.*/


                            //SOLUTION
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<algorithm>
#define ll long long
#include<vector>
#include<cmath>
#include<bitset>
#define nline '\n'
#include<climits>
#include<unordered_map>
#include<map>

void mrsumit(){
  

    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<char> ans(n,'+');
    int st=0;
    int l=n-1;
    int cont=0;
    int rem=0;
    for(int i=0; i<k; i++){
        if(s[i]=='0'){
            rem++;
            ans[st]='-';
            st++;
        }
        else if(s[i]=='1'){
            rem++;
            ans[l]='-';
            l--;
        }
        else{
            cont++;
        }
    }
    if(n-rem==cont){
        for(int i=0; i<n; i++){
            cout<<"-";
        }
        cout<<endl;
        return;
    }
    while(cont>0 && st<=l){
        ans[st]='?';
        st++;
        ans[l]='?';
        l--;
        cont--;
        
    
    }
    for(auto it: ans){
        cout<<it;
    }
    cout<<nline;
}






   
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
    mrsumit();
    }
    return 0;
}