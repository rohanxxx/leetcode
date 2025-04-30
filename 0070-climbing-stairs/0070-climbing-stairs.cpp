class Solution {
public:
/*
    we can only do 1 or 2 steps right?
    if n == 3
                    1?2
                1       2
            1   2       1   2
*/
    int func(int n, vector<int>& dp){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take1 = func(n-1, dp);
        int take2 = func(n-2, dp);
        return dp[n] = take1+take2;
    }
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            int take1 = 0, take2 = 0;
            if(i-1 >= 0) take1 = dp[i-1];
            if(i-2 >= 0) take2 = dp[i-2];
            dp[i] = take1+take2;
        }
        return dp[n];
    }
};