class Solution {
public:
    bool func(vector<int>& nums, vector<vector<int>>& dp, int i, int target){
        if(target == 0) return true;
        if(i == 0) return (nums[i] == target);
        if(dp[i][target] != -1) return dp[i][target];
        
        bool notTake = func(nums, dp, i-1, target);
        bool take = false;

        if(nums[i] <= target){
            take = func(nums, dp, i-1, target-nums[i]);
        }

        return dp[i][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return func(nums, dp, n-1, target);

        // return dp[n-1][target];
    }
};