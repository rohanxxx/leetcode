class Solution {
public: 
    int solve(vector<int>& nums, vector<int>& dp, int n){
        if(n == 0) return dp[n] = nums[n];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + solve(nums, dp, n-2);
        int notTake = solve(nums, dp, n-1);
        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);
        int take1 = solve(temp1, dp1, temp1.size()-1);
        int take2 = solve(temp2, dp2, temp2.size()-1);
        return max(take1, take2);
    }
};