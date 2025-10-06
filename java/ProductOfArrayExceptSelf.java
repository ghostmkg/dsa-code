class Solution {
    public int[] productExceptSelf(int[] nums) {
        int ans[] =new int[nums.length];
        int prefix[] =new int[nums.length];
        int suffix[] =new int[nums.length];
        int i,n=nums.length;
        prefix[0]=1;
        suffix[n-1]=1;
        for(i=1; i<n; i++)
            prefix[i]=prefix[i-1]*nums[i-1];
        for(i=n-2; i>=0; i--)
            suffix[i]=suffix[i+1]*nums[i+1];
        for(i=0; i<n; i++)
            ans[i]=prefix[i]*suffix[i];
        return ans;

    }
}