class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        //return func(nums, dp, n-1, target);
        //if(target == 0) return true;
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        //if(i == 0) return (nums[i] == target);
        //if(dp[i][target] != -1) return dp[i][target];
        if(nums[0] < target){
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i < n; i++){
            for(int t = 0; t <= target; t++){
                bool notTake = dp[i-1][t];
                bool take = false;

                if(nums[i] <= t){
                    take = dp[i-1][t-nums[i]];
                }

                dp[i][t] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
};