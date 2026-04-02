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
        int prev1 = 1;
        int prev2 = 0;
        for(int i = 0; i <= n; i++){
            int cur = 0;
            if(i == 0) continue;
            cur = prev1+prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};