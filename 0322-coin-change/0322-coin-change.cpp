class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        for(int t = 0; t <= target; t++){
            if(t % coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = INT_MAX;
        }
        // int res = func(n-1, amount, coins, dp);
        for(int i = 1; i < n; i++){
            for(int t = 0; t <= target; t++){
                int notTake = dp[i-1][t];
                int take = INT_MAX;
                if(coins[i] <= t){
                    take = dp[i][t-coins[i]];
                    if(take != INT_MAX){
                        take++;
                    }
                }
                dp[i][t] = min(take, notTake);
            }
        }
        int res = dp[n-1][target];
        if(res == INT_MAX) return -1;
        return res;
    }
};