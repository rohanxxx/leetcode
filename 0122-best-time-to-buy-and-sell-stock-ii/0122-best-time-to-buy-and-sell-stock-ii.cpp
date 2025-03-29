class Solution {
public:
    int func(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(func(i+1, 0, prices, dp) - prices[i], func(i+1, 1, prices, dp));
        }
        else{
            profit = max(prices[i] + func(i+1, 1, prices, dp), func(i+1, 0, prices, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
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