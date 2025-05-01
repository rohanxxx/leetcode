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
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for(int i = n-1; i >= 0; i--){
            for(int flag = 0; flag < 2; flag++){
                int profit = 0;
                if(flag){
                    int buy = -prices[i];
                    if(i+1 < n) buy += dp[i+1][0];
                    int notBuy = 0;
                    if(i+1 < n) notBuy = dp[i+1][1];
                    profit = max({profit, buy, notBuy});
                }
                else{
                    int sell = prices[i];
                    if(i+2 < n) sell += dp[i+2][1];
                    int notSell = 0;
                    if(i+1 < n) notSell += dp[i+1][0];
                    profit = max({profit, sell, notSell});
                }

                dp[i][flag] = profit;
            }
        }
        return dp[0][1];
    }
};