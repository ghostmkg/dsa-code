class Solution:
    def maxArea(self, h: List[int]) -> int:
        l=0
        r=len(h)-1

        ans=0
        while(l<r):
            mult=min(h[l],h[r])*(r-l)
            if mult>ans:
                ans=mult  
            if min(h[l],h[r])==h[r]:
                r-=1
            else:
                l+=1
        
        return ans