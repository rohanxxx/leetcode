class Solution {
public:
    int func(int i, int sum, vector<int>& stones, vector<vector<int>>& dp){
        if(i == -1) return sum;
        if(dp[i][sum] != -1) return dp[i][sum];
        int take = func(i-1, abs(sum-stones[i]), stones, dp);
        int notTake = func(i-1, sum+stones[i], stones, dp);
        return dp[i][sum] = min(take, notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for(int num: stones){
            sum += num;
        }
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return func(n-1, 0, stones, dp);
    }
};