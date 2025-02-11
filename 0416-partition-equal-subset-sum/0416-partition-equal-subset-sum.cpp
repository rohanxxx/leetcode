class Solution {
public:
    bool func(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) {
            return true;
        }
        if(index == 0) {
            return (nums[index] == target);
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool notTake = func(index-1, target, nums, dp);
        bool take = false;

        if(nums[index] <= target){
            take = func(index-1, target-nums[index], nums, dp);
        }

        return dp[index][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        if(sum % 2){
            return false;
        }

        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return func(nums.size()-1, target, nums, dp);
    }
};