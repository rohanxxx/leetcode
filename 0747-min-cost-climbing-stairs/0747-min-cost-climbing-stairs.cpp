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
        vector<int> dp(n+1, -1);
        return func(n, cost, dp);
    }
};