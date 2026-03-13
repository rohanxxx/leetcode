class Solution {
public:
    bool dfs(int i, int cur, vector<int>& nums, vector<vector<int>>& dp){
        if(cur == 0) return true;
        if(cur < 0) return false;
        if(i == 0) return nums[i] == cur;

        if(dp[i][cur] != -1) return dp[i][cur];

        bool take = dfs(i-1, cur-nums[i], nums, dp);
        bool notTake = dfs(i-1, cur, nums, dp);

        return dp[i][cur] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        //if odd sum partitioning is impossible
        if(sum % 2){
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));
        return dfs(n-1, sum/2, nums, dp);
    }
};