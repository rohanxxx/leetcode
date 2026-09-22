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
        //vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        vector<long long> next(2, 0), curr(2,0);
        for(int i = n-1; i >= 0; i--){
            for(int prev_i = 0; prev_i < 2; prev_i++){
                long long take = 0, notTake = 0;
                if(!prev_i || (i >= 1 && colors[i] != colors[i-1])){
                    take = nums[i] + next[1];
                }

                notTake = next[0];
                curr[prev_i] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
    /*long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));   // dp[n][0]=dp[n][1]=0, base case

        for(int i = n-1; i >= 0; i--){
            for(int prev_i = 0; prev_i <= 1; prev_i++){
                long long take = 0, notTake = 0;
                if(!prev_i || (i >= 1 && colors[i] != colors[i-1])){
                    take = nums[i] + dp[i+1][1];
                }
                notTake = dp[i+1][0];
                dp[i][prev_i] = max(take, notTake);
            }
        }

        return dp[0][0];
    }*/
};