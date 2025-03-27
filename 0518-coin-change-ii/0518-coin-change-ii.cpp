class Solution {
public:
    int func(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i == 0){
            if(target % nums[0] == 0) return 1;
            else return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int notTake = func(i-1, target, nums, dp);
        int take = 0;
        if(nums[i] <= target){
            take = func(i, target-nums[i], nums, dp);
        }
        return dp[i][target] = notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};