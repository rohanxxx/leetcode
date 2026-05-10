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
                
                int res = dp[j];
                if(res == INT_MIN){
                    continue;
                }
                take = max(take, res+1);
            }
            dp[i] = take;
        }
        int res = dp[0];
        if(res == INT_MIN){
            return -1;
        }

        return res;
    }
};