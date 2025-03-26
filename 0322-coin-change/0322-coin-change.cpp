class Solution {
public:
    int func(int n, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(n == 0){
            if(target % coins[0] == 0) return dp[0][target] = target/coins[0];
            return INT_MAX;
        }
        if(dp[n][target] != -1) return dp[n][target];

        int notTake = func(n-1, target, coins, dp);
        int take = INT_MAX;
        if(coins[n] <= target){
            take = func(n, target-coins[n], coins, dp);
            if(take != INT_MAX){
                take++;
            }
        }
        return dp[n][target] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res = func(n-1, amount, coins, dp);
        if(res == INT_MAX) return -1;
        return res;
    }
};