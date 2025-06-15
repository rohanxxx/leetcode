class Solution {
public:
    int func(vector<int>& nums, int& n, int target, vector<int>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= target){
                result += func(nums, n, target-nums[i], dp);
            }
        }
        return dp[target] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        //count = 0;
        int n = nums.size();
        vector<int> dp(target+1, -1);
        func(nums, n, target, dp);
        return dp[target];
    }
};