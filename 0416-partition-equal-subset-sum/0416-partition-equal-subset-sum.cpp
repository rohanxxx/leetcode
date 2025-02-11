class Solution {
public:
    bool func(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }
        if(i == 0){
            return (nums[i] == target);
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool take = false;
        bool notTake = func(i-1, target, nums, dp);

        if(target >= nums[i]){
            take = func(i-1, target-nums[i], nums, dp);
        }

        return dp[i][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int n: nums){
            sum += n;
        }

        if(sum % 2){
            return false;
        }

        int target = sum/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return func(n-1, target, nums, dp);
    }
};