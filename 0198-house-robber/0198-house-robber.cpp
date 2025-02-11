class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 1) return nums.back();
        if(len == 2) return max(nums[len-1], nums[len-2]);
        
        vector<int> dp(len, 0);
        dp[0] = nums[0]; dp[1] = max(nums[1], dp[0]);
        for(int i = 2; i < len; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp.back();
    }
};