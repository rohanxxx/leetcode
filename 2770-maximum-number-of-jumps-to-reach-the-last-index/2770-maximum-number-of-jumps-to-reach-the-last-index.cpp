/*          0 1 2 3 4 5
    nums = [1,3,6,4,1,2], target = 2
     0 1 2 3 4 5
    [1,3,6,4,1,2]

    
    3-1 ->2. 1-1 ->0 2-1 -> -1
*/
class Solution {
public:
    //TC: O(N*N)
    //SC: O(N*N)
    int dfs(int i, int count, vector<int>& nums, int target, vector<vector<int>>& dp){
        int n = nums.size();
        
        if(i == n-1){
            return count;
        }
        if(dp[i][count] != -1){
            return dp[i][count];
        }
        
        int take = INT_MIN;
        for(int j = i+1; j < n; j++){
            if(-target <= nums[j]-nums[i] && nums[j]-nums[i] <= target){
                take = max(take, dfs(j, count+1, nums, target, dp));
            }
        }
        return dp[i][count] = take;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        int res = dfs(0, 0, nums, target, dp);
        res = dp[0][0];
        if(res == INT_MIN){
            return -1;
        }
        return res;
    }
};