class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr1, int k, int x) {
        int index = -1;
        int smallest = INT_MAX;
        for(int i =0;i<arr1.size();i++){
            if(abs(arr1[i] - x) <smallest){
                smallest = abs(arr1[i] -x);
                index = i;
            }
        }
        vector<pair<int,int> >arr;
        for(int i = index;i>=0;i--){
            int v =abs( arr1[i] - x);
            arr.push_back(make_pair(v,i));
        }
        for(int i = index+1;i<arr1.size();i++){
            int v =abs( arr1[i] - x);
            arr.push_back(make_pair(v,i));
        }
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i =0;i<k;i++){
            ans.push_back(arr1[arr[i].second]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
