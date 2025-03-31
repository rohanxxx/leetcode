class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], dp[prev]+1);
                    maxi = max(dp[i], maxi);
                }
            }
        }

        return maxi;
    }
};