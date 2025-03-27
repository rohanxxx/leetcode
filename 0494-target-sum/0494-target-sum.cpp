class Solution {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2 * totalSum + 1, -1));
        return func(nums, 0, 0, target, dp);
    }

    int func(vector<int>& nums, int i, int currentSum, int target, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            if (currentSum == target) return 1;
            else return 0;
        } 
        
        if (dp[i][currentSum + totalSum] != -1) {
            return dp[i][currentSum + totalSum];
        }

        int add = func(nums, i + 1, currentSum + nums[i], target, dp);
        int subtract = func(nums, i + 1, currentSum - nums[i], target, dp);

        return dp[i][currentSum + totalSum] = add + subtract;
    }
};