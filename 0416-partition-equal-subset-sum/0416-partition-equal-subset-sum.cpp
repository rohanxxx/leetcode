class Solution {
public:
    bool func(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == 0) return (nums[i] == target);
        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = func(i-1, target, nums, dp);
        bool take = false;

        if(nums[i] <= target) take = func(i-1, target-nums[i], nums, dp);

        return dp[i][target] = notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(int& num: nums) sum += num;

        if(sum % 2) return false;

        int target = sum/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return func(n-1, target, nums, dp);
    }
};