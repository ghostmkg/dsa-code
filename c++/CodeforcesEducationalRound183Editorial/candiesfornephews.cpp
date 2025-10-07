/*  Problem Statment

                           A. Candies for Nephews
                        time limit per test1 second
                    memory limit per test256 megabytes
Monocarp has three nephews. New Year is coming, and Monocarp has 𝑛
 candies that he will gift to his nephews.

To ensure that none of the nephews feels left out, Monokarp wants to give each of the three nephews the same number of candies.

Determine the minimum number of candies that Monocarp needs to buy additionally so that he can give each of the three nephews the same number of candies. Note that all 𝑛
 candies that Monocarp initially has will be given to the nephews.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

Each test case consists of one line containing one integer 𝑛
 (1≤𝑛≤100
) — the number of candies that Monocarp initially has.

Output
For each test case, print one integer — the minimum number of candies that Monokarp needs to buy additionally so that he can give each of the three nephews the same number of candies.
*/


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
    
    int n;
    cin>>n;
    if(n%3==0){
        cout<<"0"<<endl;
        return;
    }
    int extra=3-(n%3);
    cout<<extra<<nline;


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