class Solution {
public:
    int func(vector<int>& nums, vector<int>& dp, int n){
        if(n == 0) return dp[n] = nums[n];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        int take = nums[n] + func(nums, dp, n-2);
        int notTake = 0+func(nums, dp, n-1);
        
        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); dp[0] = nums[0];
        // func(nums, dp, n-1);
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i-2>=0) take += dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake); 
        }
        return dp[n-1];
    }
};