class Solution {
public: 
    int solve(vector<int>& nums, vector<int>& dp, int stop, int n){
        if(n == stop) return dp[n] = nums[n];
        if(n < stop) return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + solve(nums, dp, stop, n-2);
        int notTake = solve(nums, dp, stop, n-1);
        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        solve(nums, dp1, 0, n-2);
        solve(nums, dp2, 1, n-1);
        return max(dp1[n-2], dp2[n-1]);
    }
};