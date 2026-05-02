class Solution {
public:
    int dfs(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(i == 0){
            if(amount % coins[0] == 0){
                return amount/coins[i];
            }
            return INT_MAX;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(amount == 0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = INT_MAX, notTake = INT_MAX;
        if(amount >= coins[i]){
            take = dfs(i, amount-coins[i], coins, dp);
            if(take != INT_MAX){
                take++;
            }
        }
        notTake = dfs(i-1, amount, coins, dp);
        return dp[i][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int count = dfs(n-1, amount, coins, dp);

        if(count != INT_MAX){
            return count;
        }

        return -1;
    }
};