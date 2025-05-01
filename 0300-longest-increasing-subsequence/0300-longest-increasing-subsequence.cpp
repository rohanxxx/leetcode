class Solution {
public:
/*
        [10,9,2,5,3,7,101,18]
        [2,3,7,101]

        func(i, prev_i)
        take = func(i+1, i);
        notTake = func(i+1, prev_i);
*/
    int func(int i, int prev_i, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];

        int take = 0, notTake = 0;
        if(prev_i == -1 || nums[i] > nums[prev_i]){
            take = 1+func(i+1, i, nums, dp);
        }
        notTake = func(i+1, prev_i, nums, dp);
        return dp[i][prev_i+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = n; i >= 0; i--){
            for(int prev_i = i-1; prev_i >= -1; prev_i--){
                if(i == n){
                    dp[i][prev_i+1] = 0;
                    continue;
                }
                int take = 0, notTake = 0;
                if(prev_i == -1 || nums[i] > nums[prev_i]){
                    take = 1+dp[i+1][i+1];
                }
                notTake = dp[i+1][prev_i+1];
                dp[i][prev_i+1] = max(take, notTake);
            }
        }
        //func(0, -1, nums, dp);
        return dp[0][-1+1];
    }
};