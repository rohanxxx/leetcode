class Solution {
public:
    int dfs(vector<vector<int>>& dp, vector<int>& nums, int index, int k){
        int n = nums.size();

        // last partition takes the rest
        if(k == 1){
            int sum = 0;
            for(int i = index; i < n; i++) sum += nums[i];
            return sum;
        }

        if(dp[index][k] != -1) return dp[index][k];

        int curSum = 0;
        int res = INT_MAX;

        for(int i = index; i <= n - k; i++){
            curSum += nums[i];
            int maxSum = max(curSum, dfs(dp, nums, i+1, k-1));
            res = min(res, maxSum);

            if(curSum > res) break; // pruning (same as Python)
        }

        return dp[index][k] = res;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return dfs(dp, nums, 0, k);
    }
};