// This code solves LeetCode question "875. Koko Eating Bananas", level: Medium
// The approach uses Binary Search
// The complexity analysis is---> TC: O(NlogN), SC: O(1)

#include<bits/stdc++.h>
using namespace std;

long long timeToEatBananas(int k, int n, vector<int>piles)
{
    long long sum=0;
    for(int i=0; i<n; i++)
    {
        if(piles[i]%k!=0)
            sum+=((piles[i]/k)+1);
        else
            sum+=(piles[i]/k);
    }
    return sum;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
    int low=1, high=*max_element(piles.begin(), piles.end());
    int k=high;
    while(low<=high)
    {
        int mid=(low+high)/2;
        long long h1=timeToEatBananas(mid, n, piles);
        if(h1<=(long long)h)
        {
            k=min(k,mid);
            high=mid-1;
        }
        else if(h1>h)
            low=mid+1;
    }
    return k;        
}


int main()
{
    int n,h; 
    vector<int> piles;
    cout<<"Enter the number of piles: "<<endl;
    cin>>n;
    cout<<"Enter the total number of hours Koko has to eat all the bananas:"<<endl;
    cin>>h;
    cout<<"Enter the number of bananas in each pile:"<<endl;
    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        piles.emplace_back(x);
    }
    int k=minEatingSpeed(piles,h);
    cout<<"The bananas-per-hour eating speed to finish all bananas is: "<<k;
    
}