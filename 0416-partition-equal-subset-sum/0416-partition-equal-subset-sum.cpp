class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        //vector<vector<int>> dp(n, vector<int>(target+1, 0));
        vector<int> prev(target+1, 0), curr(target+1, 0);
        //return func(nums, dp, n-1, target);
        //if(target == 0) return true;
        for(int i = 0; i < n; i++){
            prev[0] = true;
        }
        //if(i == 0) return (nums[i] == target);
        //if(dp[i][target] != -1) return dp[i][target];
        if(nums[0] <= target){
            prev[nums[0]] = true;
        }
        for(int i = 1; i < n; i++){
            for(int t = 1; t <= target; t++){
                bool notTake = prev[t];
                bool take = false;

                if(nums[i] <= t){
                    take = prev[t-nums[i]];
                }

                curr[t] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};