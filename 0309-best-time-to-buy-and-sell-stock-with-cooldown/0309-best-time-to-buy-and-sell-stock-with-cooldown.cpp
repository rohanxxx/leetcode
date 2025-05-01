class Solution {
public:
    int func(int i, int flag, vector<int>& prices, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int profit = 0;
        if(flag){
            int buy = -prices[i]+func(i+1, 0, prices, dp);
            int notBuy = func(i+1, 1, prices, dp);
            profit = max({profit, buy, notBuy});
        }
        else{
            int sell = prices[i] + func(i+2, 1, prices, dp);
            int notSell = func(i+1, 0, prices, dp);
            profit = max({profit, sell, notSell});
        }

        return dp[i][flag] = profit; 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return func(0, 1, prices, dp);
    }
};