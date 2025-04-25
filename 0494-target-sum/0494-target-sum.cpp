class Solution {
public:
    int totalSum;
    int func(int i, int currentSum, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()){
            if(currentSum == target) return 1;
            else return 0;
        }
        if(dp[i][currentSum+totalSum] != -1) return dp[i][currentSum+totalSum];
        
        int plus = func(i+1, currentSum+nums[i], target, nums, dp);
        int minus = func(i+1, currentSum-nums[i], target, nums, dp);
        
        return dp[i][currentSum+totalSum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = 0;
        for(int num: nums){
            totalSum += num;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1+totalSum*2, -1));
        return func(0, 0, target, nums, dp);
    }
};