/*
    hop rules:
    from i we can jump j > i and you get score of (j-i)*nums[j]

    return the maximum score you can get

    0 1 2
    1,5,8
*/
class Solution {
public:
    int dfs(int index, vector<int>& nums, vector<int>& dp){
        if(dp[index] != INT_MIN){
            return dp[index];
        }
        int res = 0;
        for(int i = index+1; i < nums.size(); i++){
            res = max((i - index)*nums[i] + dfs(i, nums, dp), res);
        }
        return dp[index] = res;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        return dfs(0, nums, dp);
    }
};