class Solution {
public:
    /*int dfs(int i, vector<int>& nums, vector<int>& dp){
        if(i < 0){
            return 0;
        }
        if(dp[i] != INT_MIN){
            return dp[i];
        }
        
        int take = 0;
        int notTake = 0;

        take = nums[i] + dfs(i-2, nums, dp);
        notTake = dfs(i-1, nums, dp);

        return dp[i] = max(take, notTake);
    }*/
    int rob(vector<int>& nums) {
        int n = nums.size();
        //vector<int> dp(n, 0);
        int p1 = 0, p2 = 0;
        for(int i = 0; i < n; i++){
            int cur = 0;
            int take = nums[i];
            int notTake = 0;

            if(i-2 >= 0){
                take = take + p2;
            }
            if(i-1 >= 0){
                notTake = p1;
            }

            cur = max(take, notTake);
            p2 = p1;
            p1 = cur;
        }
        return p1;
    }
};