class Solution {
public:
/*
    nums = [1,1,1,1,1]
    sum = 5 [-5 -> 10]
    sum*2 = -1+totalSum 4? 1+totalSum = 6
*/
    int func(int i, int curSum, int& sum, int& target, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()){
            if(target == curSum) return 1;
            else return 0;
        }
        if(dp[i][curSum+sum] != -1) return dp[i][curSum+sum];
        int plus = func(i+1, curSum+nums[i], sum, target, nums, dp);
        int minus = func(i+1, curSum-nums[i], sum, target, nums, dp);
        return dp[i][curSum+sum] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(1+2*sum, -1));
        return func(0, 0, sum, target, nums, dp);
    }
};