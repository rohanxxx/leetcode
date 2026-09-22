/*
    you cannot rob the adj houses if the share the same color
*/
class Solution {
public:
    long long dfs(int i, int prev_i, vector<int>& nums, vector<int>& colors, vector<vector<long long>>& dp){
        int n = nums.size();
        if(i == n){
            return 0;
        }
        if(dp[i][prev_i] != -1){
            return dp[i][prev_i];
        }
        long long take = 0, notTake = 0;
        if(!prev_i || colors[i] != colors[i-1]){
            take = nums[i] + dfs(i+1, 1, nums, colors, dp);
        }

        notTake = dfs(i+1, 0, nums, colors, dp);

        return dp[i][prev_i] = (long long)max((long long)take, (long long) notTake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return dfs(0, 0, nums, colors, dp);
    }
};