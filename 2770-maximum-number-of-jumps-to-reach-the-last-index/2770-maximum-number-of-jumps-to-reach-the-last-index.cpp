/*          0 1 2 3 4 5
    nums = [1,3,6,4,1,2], target = 2
     0 1 2 3 4 5
    [1,3,6,4,1,2]

    
    3-1 ->2. 1-1 ->0 2-1 -> -1
*/
class Solution {
public:
    //TC: O(N*N)
    //SC: O(N)
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MIN);
        dp[n-1] = 0;

        for(int i = n-1-1; i >= 0; i--){
            int take = INT_MIN;
            for(int j = i+1; j < n; j++){
                if(!(-target <= nums[j]-nums[i] && nums[j]-nums[i] <= target)){
                    continue;
                }
                if(dp[j] == INT_MIN){
                    continue;
                }
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(dp[0] == INT_MIN){
            return -1;
        }

        return dp[0];
    }
};