class Solution {
    // Push index not elements
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;

        int i=0; int j=0;

        while(j < nums.size()){
            // if need to pop then check q not empty and  pop from back then push nums[j] greater one
            // To understand it see case [ 1 3 1 2 0 5 ] and k = 3  // we doing pop back to remove smaller element then next largest
            while(q.size() > 0 && nums[q.back()] < nums[j]){
                q.pop_back();
            }

            q.push_back(j);

            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                ans.push_back(nums[q.front()]);
                // Shift Window
                if(i == q.front()){
                    q.pop_front();
                }
                i++;
                j++;
            }

        }
        return ans;
    }
};
