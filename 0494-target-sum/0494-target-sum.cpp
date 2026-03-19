class Solution {
public:
    int dfs(int i, int t, int& sum, vector<int>& nums, vector<vector<int>>& dp){
        // FIX 1: if t goes out of possible dp range
        if(t < -sum || t > sum) return 0;

        if(t == 0 && i == 0) return 1;
        if(t != 0 && i == 0) return 0;

        if(dp[i][t + sum] != -1) return dp[i][t + sum];
        
        int take1 = dfs(i-1, t-nums[i-1], sum, nums, dp); // + case
        int take2 = dfs(i-1, t+nums[i-1], sum, nums, dp); // - case
        
        return dp[i][t + sum] = take1 + take2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = 0;
        for(int num : nums){
            sum += num;
        }

        // FIX 2: impossible case
        if(target < -sum || target > sum) return 0;

        vector<vector<int>> dp(n+1, vector<int>(sum*2 + 1, -1));
        return dfs(n, target, sum, nums, dp);
    }
};