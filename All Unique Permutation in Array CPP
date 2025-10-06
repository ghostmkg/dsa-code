class Solution {
  public:
    set<vector<int>> res;
    void recur(int i,vector<int> &arr){
        if(i == arr.size()){
            res.insert(arr);
            return;
        }
        for(int j =i;j< arr.size();j++){
            swap(arr[i],arr[j]);
            recur(i+1,arr);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        recur(0,arr);
        return vector<vector<int>> (res.begin(),res.end());
    }
};
