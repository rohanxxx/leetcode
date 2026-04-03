class Solution {
public:
    /*int dfs(int i, const int& n, const vector<int>& cost, vector<int>& dp){
        if(i < 0) return 0; //just in case to avoid any sort of bound errors
        if(i == 0) return cost[0];
        if(i == 1) return cost[1];
        if(dp[i] != INT_MAX){
            return dp[i];
        }
        int curCost = 0;
        if(i < n){
            curCost = cost[i];
        }
        return dp[i] = curCost + min(dfs(i-1, n, cost, dp), dfs(i-2, n, cost, dp));
    }*/
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        vector<int> dp(n+1, 0);
        
        //if(i < 0) return 0; //just in case to avoid any sort of bound errors
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i <= n; i++){
            int curCost = 0;
            if(i < n){
                curCost = cost[i];
            }

            dp[i] = curCost + min(dp[i-1], dp[i-2]);
        }
        
        return dp[n];
    }
};