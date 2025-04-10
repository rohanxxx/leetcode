class Solution {
public:
    int func(int n, vector<int>& dp){
        if(n == 1 || n == 2){
            return dp[n] = n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = func(n-1, dp)+func(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        func(n,dp);
        return dp[n];
    }
};