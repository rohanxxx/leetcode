class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        vector<int> prev(target+1, 0);
        vector<int> cur(target+1, 0);
        for(int i = 0; i < n; i++){
            prev[0] = true;
        }
        if(nums[0] <= target){
            prev[nums[0]] = true;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= target; j++){
                bool notTake = prev[j];
                bool take = false;
                if(nums[i] <= j){
                    take = prev[j-nums[i]];
                }
                cur[j] = take || notTake;
            }
            prev = cur;
        }

        return prev[target];
    }
};