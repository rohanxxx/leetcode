class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2, 0);
        // dp[n][0] = dp[n][1] = 0;
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                int profit = 0;
                if(buy){
                    profit = max(prev[0] - prices[i], prev[1]);
                }
                else{
                    profit = max(prices[i] + prev[1], prev[0]);
                }
                prev[buy] = profit;
            }
        }
        return prev[1];
    }
};