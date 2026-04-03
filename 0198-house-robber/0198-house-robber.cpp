class Solution {
public:
    int dfs(int i, vector<int>& nums, vector<int>& dp){
        if(i < 0){
            return 0;
        }
        if(dp[i] != INT_MIN){
            return dp[i];
        }
        
        int take = 0;
        int notTake = 0;

        take = nums[i] + dfs(i-2, nums, dp);
        notTake = dfs(i-1, nums, dp);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        return dfs(n-1, nums, dp);
    }
};