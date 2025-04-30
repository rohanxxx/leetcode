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
        int prev1 = 1;
        int prev2 = 2;
        for(int i = 3; i <= n; i++){
            int take1 = prev1;
            int take2 = prev2;
            prev1 = prev2;
            prev2 = take1+take2;
        }
        return prev2;
    }
};