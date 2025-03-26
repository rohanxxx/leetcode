class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        int target = amount;
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int T = 0; T <= target; T++) {
            if(T % nums[0] == 0) dp[0][T] = T / nums[0];
            else dp[0][T] = INT_MAX;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int T = 0; T <= target; T++) {
                int notTake = 0 + dp[ind - 1][T];
                int take = INT_MAX;
                if(nums[ind] <= T) {
                    take = dp[ind][T - nums[ind]];
                    if(take != INT_MAX){
                        take++;
                    }
                }
                dp[ind][T] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][target];
        if(ans == INT_MAX) return -1;
        return ans;
    }
};