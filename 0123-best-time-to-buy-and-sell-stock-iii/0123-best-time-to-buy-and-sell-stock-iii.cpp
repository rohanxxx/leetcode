class Solution {
public:
    int func(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i == prices.size() || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        int profit = 0;
        int sell = 0, notSell = 0;
        if(buy){
            sell = func(i+1, 0, cap, prices, dp) - prices[i];
            notSell = func(i+1, 1, cap, prices, dp);
        }
        else{
            sell = prices[i] + func(i+1, 1, cap-1, prices, dp);
            notSell = func(i+1, 0, cap, prices, dp);
        }
        profit = max(sell, notSell);
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    long profit = 0;
                    int sell = 0, notSell = 0;
                    if(buy){
                        sell = dp[i+1][0][cap] - prices[i];
                        notSell = dp[i+1][1][cap];
                    }
                    else{
                        sell = prices[i] + dp[i+1][1][cap-1];
                        notSell = dp[i+1][0][cap];
                    }
                    profit = max(sell, notSell);
                    dp[i][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};