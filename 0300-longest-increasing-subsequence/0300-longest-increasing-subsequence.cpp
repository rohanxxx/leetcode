class Solution {
public:
    int func(int i, int prev_i, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
        int take = 0, notTake = 0;
        if(prev_i == -1 || nums[i]>nums[prev_i]){
            take = 1+func(i+1, i, nums, dp);
        }
        notTake = func(i+1, prev_i, nums, dp);
        return dp[i][prev_i+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return func(0, -1, nums, dp);
    }
};