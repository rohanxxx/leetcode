class Solution {
public:
    int dfs(int n, vector<int>& dp){
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
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, INT_MIN);
        return dfs(n, dp);
    }
};