class Solution {
public:
    void Permut(int ind,vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans)
{
    int i=0;
    if(ind==ds.size())
   { ans.push_back(ds);
    return;

}
for(int i=ind;i<ds.size();i++)
{
    swap(ds[ind],ds[i]);
Permut(ind+1,ds,nums,ans);
swap(ds[ind],ds[i]);
}
}
public:
    vector<vector<int>> permute(vector<int>& nums)
     {
      vector<int> ds;
        vector<vector<int>>ans;
        
        ds=nums;
        Permut(0,ds,nums,ans);
        return ans;
    }
};