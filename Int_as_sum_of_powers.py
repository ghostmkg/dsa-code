class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD=10**9+7
        # find largest m with m^x<=n
        m=int(n**(1.0/x))
        # fix rounding edge-cases
        while (m+1)**x<=n:
            m+=1
        while m**x>n:
            m-=1

        powers=[i**x for i in range(1,m+1)]
        dp=[0]*(n+1)
        dp[0]=1

        for v in powers:
            for s in range(n,v-1,-1):   # iterate backwards for 0/1 usage
                dp[s]=(dp[s]+dp[s-v])%MOD

        return dp[n]
