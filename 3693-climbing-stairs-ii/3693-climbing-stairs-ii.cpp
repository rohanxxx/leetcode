/*
    cost of jump costs[j] + (j-i)^2
*/
class Solution {
public:
    int dfs(int index, vector<int>& costs, vector<int>& dp){
        if(index == 0){
            return 0;
        }
        if(dp[index] != INT_MAX){
            return dp[index];
        }
        int res = INT_MAX;
        for(int i = 1; i <= 3; i++){
            if(index-i < 0){
                break;
            }
            res = min((costs[index-1] + (i*i)) + dfs(index-i, costs, dp), res);
        }
        return dp[index] = res;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int index = 1; index <= n; index++){
            int res = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(index-i < 0){
                    continue;
                }
                res = min((costs[index-1] + (i*i)) + dp[index-i], res);
            }
            dp[index] = res;
        }
        //return dfs(n, costs, dp);
        return dp[n];
    }
};