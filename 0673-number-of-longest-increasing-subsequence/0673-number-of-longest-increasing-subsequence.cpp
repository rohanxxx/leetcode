class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1;
        vector<int> dp(n, 1), count(n, 1);
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && dp[prev]+1 > dp[i]){
                    dp[i] = 1+dp[prev];
                    count[i] = count[prev];
                    continue;
                }
                if(nums[prev] < nums[i] && dp[prev]+1 == dp[i]){
                    count[i] += count[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int nlsc = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi){
                nlsc += count[i];
            }
        }

        return nlsc;
    }
};