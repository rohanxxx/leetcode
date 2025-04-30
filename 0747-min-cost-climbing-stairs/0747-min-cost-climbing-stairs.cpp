class Solution {
public:
    int func(int n, vector<int>& cost, vector<int>& dp){
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];
        if(dp[n] != -1) return dp[n];
        int take1 = func(n-1, cost, dp);
        int take2 = func(n-2, cost, dp);
        int curCost;
        if(n == cost.size()){
            curCost = 0;
        }
        else{
            curCost = cost[n];
        }
        return dp[n] = curCost+min(take1, take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];
        if(n == 2) return min(cost[0], cost[1]);
        
        vector<int> dp(n+1, 0);
        int prev0 = cost[0];
        int prev1 = cost[1];
        for(int i = 2; i <= n; i++){
            int take1 = prev0;
            int take2 = prev1;
            
            int curCost;
            if(i == n) curCost = 0;
            else curCost = cost[i];
            prev0 = prev1;
            prev1 = curCost + min(take1, take2);
        }
        return prev1;
    }
};