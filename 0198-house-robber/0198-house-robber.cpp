/*
            0 1 2 3
    nums = [1,2,3,1]
*/
class Solution {
public:
    int dfs(int i, vector<int>& nums, vector<int>& dp){
        if(i < 0) return 0;
        if(dp[i] != INT_MIN) return dp[i];

        int take = nums[i] + dfs(i-2, nums, dp);
        int notTake = dfs(i-1, nums, dp);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            int take = nums[i];
            int notTake = 0; 
            if(i-2 >= 0) take += dp[i-2];
            if(i-1 >= 0) notTake += dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dfs(n-1, nums, dp);
    }
};