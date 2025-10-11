 class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0; 
        int minPrice = prices[0]; 
        int maxProfit = 0;         
        for(int i=1; i<prices.size(); i++){
            maxProfit = max(maxProfit, prices[i] - minPrice); // max check which is maximum between the two value
            minPrice = min(minPrice, prices[i]); 
        }
        return maxProfit;
    }
};
