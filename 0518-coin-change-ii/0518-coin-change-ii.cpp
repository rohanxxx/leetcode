class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0){
                dp[0][t] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= amount; t++){
                int notTake = dp[i-1][t];
                int take = 0;
                if(coins[i] <= t){
                    take = dp[i][t-coins[i]];
                }
                
                if((long)notTake+take >= (long)INT_MAX){
                    dp[i][t] = 0;
                }
                else{
                    dp[i][t] = notTake+take;
                }
            }
        }

        return dp[n-1][amount];
    }
};