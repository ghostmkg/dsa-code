class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minimum = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minimum){
                minimum = prices[i];
            }
            else{
                if(prices[i] - minimum > maxProfit){
                    maxProfit = prices[i] - minimum;
                }
            }
        }

        return maxProfit;

    }
};