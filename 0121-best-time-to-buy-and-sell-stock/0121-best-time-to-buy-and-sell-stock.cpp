class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] > minPrice){
                maxProfit = max(maxProfit, prices[i]-minPrice);
            }
            minPrice = min(prices[i], minPrice);
        }
        return maxProfit; 
    }
};