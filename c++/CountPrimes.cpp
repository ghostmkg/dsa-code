class Solution {
public:
    int countPrimes(int n)  {
        
vector <int>prime(n+1,1);
        int i, j;
        
        for( i=2 ;i*i<=n;i++)
            {
               if(prime[i]==1)
                   
                for(j=i*i ; j<=n;j+=i)
                    {
                        prime[j]=0;
                    }
            }
        //now push the nose with1 in another array 
        int count=0;
        vector<int>primenos;
        for(i=2;i<n;i++)
            {
                if(prime[i]==1)
                    count++;
            }
        return count;
            
    }
};