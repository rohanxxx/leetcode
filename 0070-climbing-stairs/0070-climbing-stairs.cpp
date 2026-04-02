class Solution {
public:
    /*int dfs(int n, vector<int>& dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(dp[n] != INT_MIN){
            return dp[n];
        }
        return dp[n] = dfs(n-1, dp) + dfs(n-2, dp);
    }*/
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        //return dfs(n, dp);
        dp[0] = 1;
        for(int i = 0; i <= n; i++){
            if(i == 0){
                continue;
            }
            if(i-1 >= 0) dp[i] += dp[i-1];
            if(i-2 >= 0) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};