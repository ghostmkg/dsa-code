class Solution {
public:
    int findDays(vector<int>& weights, int cap)
    {
        int Day = 1, load = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            if(weights[i]+load > cap)
            {
                Day += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return Day;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high)
        {
            int mid = low +(high - low)/2;
            int noOFdays = findDays(weights,mid);
            if(noOFdays <= days)
            {
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
