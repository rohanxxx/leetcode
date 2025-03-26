class Solution {
public:
    int func(int ind, int T, vector<int> &nums, vector<vector<int>> &dp) {
        if(ind == 0) {
            if(T % nums[0] == 0) return T / nums[0];
            return 1e9;
        }

        if(dp[ind][T] != -1) return dp[ind][T];

        int notTake = 0 + func(ind - 1, T, nums, dp);
        int take = INT_MAX;

        if(nums[ind] <= T) {
            take = 1 + func(ind, T - nums[ind], nums, dp);
        }

        return dp[ind][T] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res = func(n-1, amount, coins, dp);
        if(res == 1e9) return -1;
        return res;
    }
};